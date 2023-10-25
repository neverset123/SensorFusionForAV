resolution_range = 1
range_max = 300
c = 3e8

% TODO : Find the Bsweep of chirp for 1 m resolution
Bsweep = c / (2 * resolution_range)

% TODO : Calculate the chirp time based on the Radar's Max Range
Tchirp = 5.5*2*range_max/c

% TODO : define the frequency shifts 
for fb = [0.0, 1.1, 13, 24]
    range = c*fb*Tchirp/(2*Bsweep)
    disp(range)
end
