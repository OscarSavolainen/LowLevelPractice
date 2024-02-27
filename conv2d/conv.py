import torch

x = torch.Tensor([[0, 1, 2],
                [3, 4, 5],
                [6, 7, 8]])

w3 = torch.Tensor([[0, 0, 0],
                [1, 1, 1],
                [-1, -1, -1]])

#x = torch.Tensor([[0, 1, 2, 3],
                  #[4, 5, 6, 7]])
#w = torch.Tensor([
    #[0, 1],
    #[0, 1],
    #[0, 1],
    #[0, 1],
#])

import ipdb
ipdb.set_trace()
w2 = torch.nn.Conv2d(1,1,(3,3), padding='same')
w2.weight.data = w3.view(1,1,3,3)
x = x.view(1,1,3,3)
y = w2(x)
#y = x@w

