import numpy as np
import matplotlib.pyplot as plt
from IPython.display import clear_output
import time
import imageio

gifname = "GOL"

print("loading game")
test = np.loadtxt("test.txt")

Ngrid = test.shape[1]

frames = int(test.shape[0]/Ngrid)

game = test.reshape((frames,Ngrid,Ngrid))[0:]

print("making frames")
for i,x in enumerate(game):
    fig, ax = plt.subplots(1, figsize=[10,10])
    ax.imshow(game[i])
    ax.set_title(f"frame {i}", fontdict={"color":"w"})
    ax.set_xticks([])
    ax.set_yticks([])
    ax.set_xticklabels([])
    ax.set_yticklabels([])
    plt.savefig(f"pngs/frame{i}.png",dpi=100)
    plt.close()
    print(f"frame = {i}")
    clear_output(wait=True)
    
print("making gif")
imlist = []
for i in range(frames):
    im = imageio.imread(f"pngs/frame{i}.png")
    imlist.append(im)
    print(f"frame = {i}")
    clear_output(wait=True)
imageio.mimsave(f"{gifname}.gif", imlist)