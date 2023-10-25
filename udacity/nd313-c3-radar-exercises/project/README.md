## Implementation steps for the 2D CFAR
1. sliding the window with size of 2(T+G)+1 across the complete 2D array. 
2. For each step, get average of the signal within all the leading training cells to determine the noise threshold.
3. Compare the signal from the window starting point against the threshold. If the level of the signal measured in CUT is larger than the threshold measured, then assign 1 to the final signal within CUT.

## Selection of Training, Guard cells and offset
with some tries I applied following parameter for clustering: 
Gr = 2;
Gd = 1;
offset = 7;

## Steps taken to suppress the non-thresholded cells at the edges
initialize a 2d array with zeros of same size of original RDM, so that signals at the edges are automatically suppressed.