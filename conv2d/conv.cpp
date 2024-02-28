#include <iostream>
#include <vector>

std::vector<std::vector<std::vector<int>>> Conv2D(std::vector<std::vector<std::vector<std::vector<int>>>>& kernel, std::vector<std::vector<std::vector<int>>>& image) {
    // We ignore batch dimension
    size_t imageChannels = image.size();
    size_t imageHeight = image[0].size();
    size_t imageWidth = image[0][0].size();

    size_t kernelOutChannels = kernel.size();
    size_t kernelInChannels = kernel[0].size();
    size_t kernelHeight = kernel[0][0].size();
    size_t kernelWidth = kernel[0][0][0].size();

    std::vector<std::vector<std::vector<int>>> result(kernelOutChannels, std::vector<std::vector<int>>(imageHeight, std::vector<int>(imageWidth, 0) ));

    for (int ih = 0; ih < imageHeight; ++ih) {
        for (int iw = 0; iw < imageWidth; ++iw) {
            for (int ic = 0; ic < imageChannels; ++ic) {
                // We're at a fixed point of the output now, now we use the kernel and the input to compute it.

                for (int kic = 0; kic < kernelInChannels; ++kic) {
                    for (int koc = 0; koc < kernelOutChannels; ++koc) {
                        for (int kh = 0; kh < kernelHeight; ++kh) {
                            for (int kw = 0; kw < kernelWidth; ++kw) {
                                // Calculate the coordinates of the input image. We use the kernel, relative to the output pixel,
                                // to get the input image coords.
                                // NOTE: padding is "same" mode, as we don't have it and ignore values outside
                                // the kernel range
                                int py = ih - kernelHeight/2 + kh; 
                                int px = iw - kernelWidth/2 + kw; 

                                if (px >= 0 && px < imageWidth && py >= 0 && py < imageHeight) {
                                    result[koc][ih][iw] += image[ic][py][px] * kernel[kic][koc][kh][kw]; 
                                } 
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}



int main() {

    std::vector<std::vector<std::vector<int>>> image = {
        {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
        },
    };
    std::vector<std::vector<std::vector<std::vector<int>>>> kernel = {
        {
            {
                {0, 0, 0},
                {1, 1, 1},
                {-1, -1, -1},
            },
        },
    };

    std::vector<std::vector<std::vector<int>>> result = Conv2D(kernel, image);

    for (const auto& out_chan : result) {
        for (const auto& height : out_chan) {
            for (int width : height) {
                std::cout << width << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}