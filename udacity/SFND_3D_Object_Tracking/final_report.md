## MP1
code is implemented in camFusion_Student.cpp line 275-309

## MP2
code is implemented in camFusion_Student.cpp line 251-268. distance is compare with average distance of all matched lidar points to filter out outliers.

## MP3
code is implemented in camFusion_Student.cpp line 163-189. outliers is filtered with euclidean distance comparision of average and current keypoints.

## MP4
code is implemented in camFusion_Student.cpp line 193-229. distance is checked with min distance for avoid estimation errors.

## FP5

from the caculated lidar ttc time it seems that the 5 and 8 frames are way off. Reasons are there are a lot of other vehicles on the road and lidar is very sensible to metals, there could be bad lidar points that reflected from other objects (vehicles), which is wrongly included in the preceding vehicle bounding box.
"""
5 frame is loaded.
lidar time to collision: 7.11572
camera time to collision: 18.554

8 frame is loaded.
lidar time to collision: 34.3404
camera time to collision: 14.2484

"""

## MP FP6
from following logs we can see that the combination of SIFT detector and SIFT descriptor is mostly stable and reliable;combination of ORB detector and FREAK descriptor results in several negative TTC values, which could be caused by wrong feature matches.

`` `` ``
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
SHITOMASI detector and BRIEF descriptor result in camera TTC: 15.2836
3 frame is loaded.
lidar TTC: 12.264
SHITOMASI detector and BRIEF descriptor result in camera TTC: 15.4948
4 frame is loaded.
lidar TTC: 13.9161
SHITOMASI detector and BRIEF descriptor result in camera TTC: 18.2838
5 frame is loaded.
lidar TTC: 7.11572
SHITOMASI detector and BRIEF descriptor result in camera TTC: 18.8847
6 frame is loaded.
lidar TTC: 16.2511
SHITOMASI detector and BRIEF descriptor result in camera TTC: 12.8286
7 frame is loaded.
lidar TTC: 12.4213
SHITOMASI detector and BRIEF descriptor result in camera TTC: 17.5461
8 frame is loaded.
lidar TTC: 34.3404
SHITOMASI detector and BRIEF descriptor result in camera TTC: 67.5671
9 frame is loaded.
lidar TTC: 9.34376
SHITOMASI detector and BRIEF descriptor result in camera TTC: 12.071
10 frame is loaded.
lidar TTC: 18.1318
SHITOMASI detector and BRIEF descriptor result in camera TTC: 12.0973
11 frame is loaded.
lidar TTC: 18.0318
SHITOMASI detector and BRIEF descriptor result in camera TTC: 13.3811
12 frame is loaded.
lidar TTC: 3.83244
SHITOMASI detector and BRIEF descriptor result in camera TTC: 12.5928
13 frame is loaded.
lidar TTC: nan
SHITOMASI detector and BRIEF descriptor result in camera TTC: 12.7249
14 frame is loaded.
lidar TTC: 9.22307
SHITOMASI detector and BRIEF descriptor result in camera TTC: 14.7653
15 frame is loaded.
lidar TTC: 10.9678
SHITOMASI detector and BRIEF descriptor result in camera TTC: 13.4568
16 frame is loaded.
lidar TTC: 8.09422
SHITOMASI detector and BRIEF descriptor result in camera TTC: 14.9053
17 frame is loaded.
lidar TTC: 3.17535
SHITOMASI detector and BRIEF descriptor result in camera TTC: 9.37784
18 frame is loaded.
lidar TTC: nan
SHITOMASI detector and BRIEF descriptor result in camera TTC: 11.8979
19 frame is loaded.
lidar TTC: 8.30978
SHITOMASI detector and BRIEF descriptor result in camera TTC: 7.03824
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
SHITOMASI detector and ORB descriptor result in camera TTC: 16.2873
3 frame is loaded.
lidar TTC: 12.264
SHITOMASI detector and ORB descriptor result in camera TTC: 16.6724
4 frame is loaded.
lidar TTC: 13.9161
SHITOMASI detector and ORB descriptor result in camera TTC: 11.6086
5 frame is loaded.
lidar TTC: 7.11572
SHITOMASI detector and ORB descriptor result in camera TTC: 13.9845
6 frame is loaded.
lidar TTC: 16.2511
SHITOMASI detector and ORB descriptor result in camera TTC: 13.408
7 frame is loaded.
lidar TTC: 12.4213
SHITOMASI detector and ORB descriptor result in camera TTC: 17.3811
8 frame is loaded.
lidar TTC: 34.3404
SHITOMASI detector and ORB descriptor result in camera TTC: 17.4025
9 frame is loaded.
lidar TTC: 9.34376
SHITOMASI detector and ORB descriptor result in camera TTC: 11.1679
10 frame is loaded.
lidar TTC: 18.1318
SHITOMASI detector and ORB descriptor result in camera TTC: 11.0927
11 frame is loaded.
lidar TTC: 18.0318
SHITOMASI detector and ORB descriptor result in camera TTC: 12.8543
12 frame is loaded.
lidar TTC: 3.83244
SHITOMASI detector and ORB descriptor result in camera TTC: 9.90329
13 frame is loaded.
lidar TTC: nan
SHITOMASI detector and ORB descriptor result in camera TTC: 12.6372
14 frame is loaded.
lidar TTC: 9.22307
SHITOMASI detector and ORB descriptor result in camera TTC: 11.4794
15 frame is loaded.
lidar TTC: 10.9678
SHITOMASI detector and ORB descriptor result in camera TTC: 14.6577
16 frame is loaded.
lidar TTC: 8.09422
SHITOMASI detector and ORB descriptor result in camera TTC: 9.55836
17 frame is loaded.
lidar TTC: 3.17535
SHITOMASI detector and ORB descriptor result in camera TTC: 12.1643
18 frame is loaded.
lidar TTC: nan
SHITOMASI detector and ORB descriptor result in camera TTC: 10.9716
19 frame is loaded.
lidar TTC: 8.30978
SHITOMASI detector and ORB descriptor result in camera TTC: 9.49158
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
SHITOMASI detector and FREAK descriptor result in camera TTC: 15.0193
3 frame is loaded.
lidar TTC: 12.264
SHITOMASI detector and FREAK descriptor result in camera TTC: 15.2003
4 frame is loaded.
lidar TTC: 13.9161
SHITOMASI detector and FREAK descriptor result in camera TTC: 10.1709
5 frame is loaded.
lidar TTC: 7.11572
SHITOMASI detector and FREAK descriptor result in camera TTC: 13.7381
6 frame is loaded.
lidar TTC: 16.2511
SHITOMASI detector and FREAK descriptor result in camera TTC: 15.3364
7 frame is loaded.
lidar TTC: 12.4213
SHITOMASI detector and FREAK descriptor result in camera TTC: 18.7506
8 frame is loaded.
lidar TTC: 34.3404
SHITOMASI detector and FREAK descriptor result in camera TTC: 13.8845
9 frame is loaded.
lidar TTC: 9.34376
SHITOMASI detector and FREAK descriptor result in camera TTC: 13.1489
10 frame is loaded.
lidar TTC: 18.1318
SHITOMASI detector and FREAK descriptor result in camera TTC: 11.411
11 frame is loaded.
lidar TTC: 18.0318
SHITOMASI detector and FREAK descriptor result in camera TTC: 14.2096
12 frame is loaded.
lidar TTC: 3.83244
SHITOMASI detector and FREAK descriptor result in camera TTC: 11.87
13 frame is loaded.
lidar TTC: nan
SHITOMASI detector and FREAK descriptor result in camera TTC: 11.1525
14 frame is loaded.
lidar TTC: 9.22307
SHITOMASI detector and FREAK descriptor result in camera TTC: 11.7866
15 frame is loaded.
lidar TTC: 10.9678
SHITOMASI detector and FREAK descriptor result in camera TTC: 11.1615
16 frame is loaded.
lidar TTC: 8.09422
SHITOMASI detector and FREAK descriptor result in camera TTC: 9.42166
17 frame is loaded.
lidar TTC: 3.17535
SHITOMASI detector and FREAK descriptor result in camera TTC: 14.653
18 frame is loaded.
lidar TTC: nan
SHITOMASI detector and FREAK descriptor result in camera TTC: 11.0132
19 frame is loaded.
lidar TTC: 8.30978
SHITOMASI detector and FREAK descriptor result in camera TTC: 8.94328
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
SHITOMASI detector and SIFT descriptor result in camera TTC: 16.5502
3 frame is loaded.
lidar TTC: 12.264
SHITOMASI detector and SIFT descriptor result in camera TTC: 17.9135
4 frame is loaded.
lidar TTC: 13.9161
SHITOMASI detector and SIFT descriptor result in camera TTC: 15.1334
5 frame is loaded.
lidar TTC: 7.11572
SHITOMASI detector and SIFT descriptor result in camera TTC: 14.0237
6 frame is loaded.
lidar TTC: 16.2511
SHITOMASI detector and SIFT descriptor result in camera TTC: 15.215
7 frame is loaded.
lidar TTC: 12.4213
SHITOMASI detector and SIFT descriptor result in camera TTC: 17.5461
8 frame is loaded.
lidar TTC: 34.3404
SHITOMASI detector and SIFT descriptor result in camera TTC: 15.7333
9 frame is loaded.
lidar TTC: 9.34376
SHITOMASI detector and SIFT descriptor result in camera TTC: 17.8523
10 frame is loaded.
lidar TTC: 18.1318
SHITOMASI detector and SIFT descriptor result in camera TTC: 13.2091
11 frame is loaded.
lidar TTC: 18.0318
SHITOMASI detector and SIFT descriptor result in camera TTC: 14.4155
12 frame is loaded.
lidar TTC: 3.83244
SHITOMASI detector and SIFT descriptor result in camera TTC: 12.6631
13 frame is loaded.
lidar TTC: nan
SHITOMASI detector and SIFT descriptor result in camera TTC: 11.2522
14 frame is loaded.
lidar TTC: 9.22307
SHITOMASI detector and SIFT descriptor result in camera TTC: 11.3034
15 frame is loaded.
lidar TTC: 10.9678
SHITOMASI detector and SIFT descriptor result in camera TTC: 13.4206
16 frame is loaded.
lidar TTC: 8.09422
SHITOMASI detector and SIFT descriptor result in camera TTC: 13.6733
17 frame is loaded.
lidar TTC: 3.17535
SHITOMASI detector and SIFT descriptor result in camera TTC: 12.1345
18 frame is loaded.
lidar TTC: nan
SHITOMASI detector and SIFT descriptor result in camera TTC: 10.9681
19 frame is loaded.
lidar TTC: 8.30978
SHITOMASI detector and SIFT descriptor result in camera TTC: 10.8876
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
HARRIS detector and BRIEF descriptor result in camera TTC: 16.3896
3 frame is loaded.
lidar TTC: 12.264
HARRIS detector and BRIEF descriptor result in camera TTC: 13.7209
4 frame is loaded.
lidar TTC: 13.9161
HARRIS detector and BRIEF descriptor result in camera TTC: 20.453
5 frame is loaded.
lidar TTC: 7.11572
HARRIS detector and BRIEF descriptor result in camera TTC: 20.8615
6 frame is loaded.
lidar TTC: 16.2511
HARRIS detector and BRIEF descriptor result in camera TTC: 17.5563
7 frame is loaded.
lidar TTC: 12.4213
HARRIS detector and BRIEF descriptor result in camera TTC: 16.5676
8 frame is loaded.
lidar TTC: 34.3404
HARRIS detector and BRIEF descriptor result in camera TTC: 14.7999
9 frame is loaded.
lidar TTC: 9.34376
HARRIS detector and BRIEF descriptor result in camera TTC: 23.3858
10 frame is loaded.
lidar TTC: 18.1318
HARRIS detector and BRIEF descriptor result in camera TTC: 12.7716
11 frame is loaded.
lidar TTC: 18.0318
HARRIS detector and BRIEF descriptor result in camera TTC: 15.5891
12 frame is loaded.
lidar TTC: 3.83244
HARRIS detector and BRIEF descriptor result in camera TTC: 13.8744
13 frame is loaded.
lidar TTC: nan
HARRIS detector and BRIEF descriptor result in camera TTC: 12.3422
14 frame is loaded.
lidar TTC: 9.22307
HARRIS detector and BRIEF descriptor result in camera TTC: 14.2441
15 frame is loaded.
lidar TTC: 10.9678
HARRIS detector and BRIEF descriptor result in camera TTC: 14.5592
16 frame is loaded.
lidar TTC: 8.09422
HARRIS detector and BRIEF descriptor result in camera TTC: 9.41062
17 frame is loaded.
lidar TTC: 3.17535
HARRIS detector and BRIEF descriptor result in camera TTC: 14.4069
18 frame is loaded.
lidar TTC: nan
HARRIS detector and BRIEF descriptor result in camera TTC: 10.4942
19 frame is loaded.
lidar TTC: 8.30978
HARRIS detector and BRIEF descriptor result in camera TTC: 15.9836
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
HARRIS detector and ORB descriptor result in camera TTC: 16.3896
3 frame is loaded.
lidar TTC: 12.264
HARRIS detector and ORB descriptor result in camera TTC: 13.6057
4 frame is loaded.
lidar TTC: 13.9161
HARRIS detector and ORB descriptor result in camera TTC: 24.9281
5 frame is loaded.
lidar TTC: 7.11572
HARRIS detector and ORB descriptor result in camera TTC: 20.4477
6 frame is loaded.
lidar TTC: 16.2511
HARRIS detector and ORB descriptor result in camera TTC: 16.5317
7 frame is loaded.
lidar TTC: 12.4213
HARRIS detector and ORB descriptor result in camera TTC: 16.5676
8 frame is loaded.
lidar TTC: 34.3404
HARRIS detector and ORB descriptor result in camera TTC: 14.4928
9 frame is loaded.
lidar TTC: 9.34376
HARRIS detector and ORB descriptor result in camera TTC: 16.8206
10 frame is loaded.
lidar TTC: 18.1318
HARRIS detector and ORB descriptor result in camera TTC: 12.7716
11 frame is loaded.
lidar TTC: 18.0318
HARRIS detector and ORB descriptor result in camera TTC: 14.9645
12 frame is loaded.
lidar TTC: 3.83244
HARRIS detector and ORB descriptor result in camera TTC: 13.7222
13 frame is loaded.
lidar TTC: nan
HARRIS detector and ORB descriptor result in camera TTC: 12.3422
14 frame is loaded.
lidar TTC: 9.22307
HARRIS detector and ORB descriptor result in camera TTC: 14.2441
15 frame is loaded.
lidar TTC: 10.9678
HARRIS detector and ORB descriptor result in camera TTC: 14.5592
16 frame is loaded.
lidar TTC: 8.09422
HARRIS detector and ORB descriptor result in camera TTC: 10.4968
17 frame is loaded.
lidar TTC: 3.17535
HARRIS detector and ORB descriptor result in camera TTC: 14.4069
18 frame is loaded.
lidar TTC: nan
HARRIS detector and ORB descriptor result in camera TTC: 11.7455
19 frame is loaded.
lidar TTC: 8.30978
HARRIS detector and ORB descriptor result in camera TTC: 15.3191
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
HARRIS detector and FREAK descriptor result in camera TTC: 14.7105
3 frame is loaded.
lidar TTC: 12.264
HARRIS detector and FREAK descriptor result in camera TTC: 13.0775
4 frame is loaded.
lidar TTC: 13.9161
HARRIS detector and FREAK descriptor result in camera TTC: 22.4747
5 frame is loaded.
lidar TTC: 7.11572
HARRIS detector and FREAK descriptor result in camera TTC: 18.8895
6 frame is loaded.
lidar TTC: 16.2511
HARRIS detector and FREAK descriptor result in camera TTC: 9.85059
7 frame is loaded.
lidar TTC: 12.4213
HARRIS detector and FREAK descriptor result in camera TTC: 17.2644
8 frame is loaded.
lidar TTC: 34.3404
HARRIS detector and FREAK descriptor result in camera TTC: 12.8879
9 frame is loaded.
lidar TTC: 9.34376
HARRIS detector and FREAK descriptor result in camera TTC: 18.1561
10 frame is loaded.
lidar TTC: 18.1318
HARRIS detector and FREAK descriptor result in camera TTC: 13.0919
11 frame is loaded.
lidar TTC: 18.0318
HARRIS detector and FREAK descriptor result in camera TTC: 13.5683
12 frame is loaded.
lidar TTC: 3.83244
HARRIS detector and FREAK descriptor result in camera TTC: 14.3153
13 frame is loaded.
lidar TTC: nan
HARRIS detector and FREAK descriptor result in camera TTC: 14.3557
14 frame is loaded.
lidar TTC: 9.22307
HARRIS detector and FREAK descriptor result in camera TTC: 9.49784
15 frame is loaded.
lidar TTC: 10.9678
HARRIS detector and FREAK descriptor result in camera TTC: 13.8575
16 frame is loaded.
lidar TTC: 8.09422
HARRIS detector and FREAK descriptor result in camera TTC: 8.52307
17 frame is loaded.
lidar TTC: 3.17535
HARRIS detector and FREAK descriptor result in camera TTC: 15.1885
18 frame is loaded.
lidar TTC: nan
HARRIS detector and FREAK descriptor result in camera TTC: 8.9141
19 frame is loaded.
lidar TTC: 8.30978
HARRIS detector and FREAK descriptor result in camera TTC: 11.9045
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
HARRIS detector and SIFT descriptor result in camera TTC: 15.0584
3 frame is loaded.
lidar TTC: 12.264
HARRIS detector and SIFT descriptor result in camera TTC: 12.8078
4 frame is loaded.
lidar TTC: 13.9161
HARRIS detector and SIFT descriptor result in camera TTC: 25.3387
5 frame is loaded.
lidar TTC: 7.11572
HARRIS detector and SIFT descriptor result in camera TTC: 22.2016
6 frame is loaded.
lidar TTC: 16.2511
HARRIS detector and SIFT descriptor result in camera TTC: 16.6751
7 frame is loaded.
lidar TTC: 12.4213
HARRIS detector and SIFT descriptor result in camera TTC: 16.5676
8 frame is loaded.
lidar TTC: 34.3404
HARRIS detector and SIFT descriptor result in camera TTC: 14.5893
9 frame is loaded.
lidar TTC: 9.34376
HARRIS detector and SIFT descriptor result in camera TTC: 23.3858
10 frame is loaded.
lidar TTC: 18.1318
HARRIS detector and SIFT descriptor result in camera TTC: 12.7716
11 frame is loaded.
lidar TTC: 18.0318
HARRIS detector and SIFT descriptor result in camera TTC: 14.9645
12 frame is loaded.
lidar TTC: 3.83244
HARRIS detector and SIFT descriptor result in camera TTC: 13.8744
13 frame is loaded.
lidar TTC: nan
HARRIS detector and SIFT descriptor result in camera TTC: 12.3422
14 frame is loaded.
lidar TTC: 9.22307
HARRIS detector and SIFT descriptor result in camera TTC: 14.3756
15 frame is loaded.
lidar TTC: 10.9678
HARRIS detector and SIFT descriptor result in camera TTC: 14.5592
16 frame is loaded.
lidar TTC: 8.09422
HARRIS detector and SIFT descriptor result in camera TTC: 10.4968
17 frame is loaded.
lidar TTC: 3.17535
HARRIS detector and SIFT descriptor result in camera TTC: 17.1599
18 frame is loaded.
lidar TTC: nan
HARRIS detector and SIFT descriptor result in camera TTC: 10.3449
19 frame is loaded.
lidar TTC: 8.30978
HARRIS detector and SIFT descriptor result in camera TTC: 13.9021
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
FAST detector and BRIEF descriptor result in camera TTC: 9.914
3 frame is loaded.
lidar TTC: 12.264
FAST detector and BRIEF descriptor result in camera TTC: 15.8028
4 frame is loaded.
lidar TTC: 13.9161
FAST detector and BRIEF descriptor result in camera TTC: 21.5055
5 frame is loaded.
lidar TTC: 7.11572
FAST detector and BRIEF descriptor result in camera TTC: 18.554
6 frame is loaded.
lidar TTC: 16.2511
FAST detector and BRIEF descriptor result in camera TTC: 26.4164
7 frame is loaded.
lidar TTC: 12.4213
FAST detector and BRIEF descriptor result in camera TTC: 20.0355
8 frame is loaded.
lidar TTC: 34.3404
FAST detector and BRIEF descriptor result in camera TTC: 14.2484
9 frame is loaded.
lidar TTC: 9.34376
FAST detector and BRIEF descriptor result in camera TTC: 15.7925
10 frame is loaded.
lidar TTC: 18.1318
FAST detector and BRIEF descriptor result in camera TTC: 16.6237
11 frame is loaded.
lidar TTC: 18.0318
FAST detector and BRIEF descriptor result in camera TTC: 15.5118
12 frame is loaded.
lidar TTC: 3.83244
FAST detector and BRIEF descriptor result in camera TTC: 19.1923
13 frame is loaded.
lidar TTC: nan
FAST detector and BRIEF descriptor result in camera TTC: 14.6099
14 frame is loaded.
lidar TTC: 9.22307
FAST detector and BRIEF descriptor result in camera TTC: 12.1794
15 frame is loaded.
lidar TTC: 10.9678
FAST detector and BRIEF descriptor result in camera TTC: 12.0074
16 frame is loaded.
lidar TTC: 8.09422
FAST detector and BRIEF descriptor result in camera TTC: 14.5428
17 frame is loaded.
lidar TTC: 3.17535
FAST detector and BRIEF descriptor result in camera TTC: 14.2291
18 frame is loaded.
lidar TTC: nan
FAST detector and BRIEF descriptor result in camera TTC: 9.15535
19 frame is loaded.
lidar TTC: 8.30978
FAST detector and BRIEF descriptor result in camera TTC: 12.9644
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
FAST detector and ORB descriptor result in camera TTC: 12.782
3 frame is loaded.
lidar TTC: 12.264
FAST detector and ORB descriptor result in camera TTC: 15.9195
4 frame is loaded.
lidar TTC: 13.9161
FAST detector and ORB descriptor result in camera TTC: 22.8128
5 frame is loaded.
lidar TTC: 7.11572
FAST detector and ORB descriptor result in camera TTC: 16.1923
6 frame is loaded.
lidar TTC: 16.2511
FAST detector and ORB descriptor result in camera TTC: 24.8536
7 frame is loaded.
lidar TTC: 12.4213
FAST detector and ORB descriptor result in camera TTC: 21.2853
8 frame is loaded.
lidar TTC: 34.3404
FAST detector and ORB descriptor result in camera TTC: 15.7082
9 frame is loaded.
lidar TTC: 9.34376
FAST detector and ORB descriptor result in camera TTC: 14.2505
10 frame is loaded.
lidar TTC: 18.1318
FAST detector and ORB descriptor result in camera TTC: 14.171
11 frame is loaded.
lidar TTC: 18.0318
FAST detector and ORB descriptor result in camera TTC: 16.6769
12 frame is loaded.
lidar TTC: 3.83244
FAST detector and ORB descriptor result in camera TTC: 27.3267
13 frame is loaded.
lidar TTC: nan
FAST detector and ORB descriptor result in camera TTC: 15.0286
14 frame is loaded.
lidar TTC: 9.22307
FAST detector and ORB descriptor result in camera TTC: 14.8569
15 frame is loaded.
lidar TTC: 10.9678
FAST detector and ORB descriptor result in camera TTC: 10.1838
16 frame is loaded.
lidar TTC: 8.09422
FAST detector and ORB descriptor result in camera TTC: 9.82786
17 frame is loaded.
lidar TTC: 3.17535
FAST detector and ORB descriptor result in camera TTC: 9.35729
18 frame is loaded.
lidar TTC: nan
FAST detector and ORB descriptor result in camera TTC: 10.7327
19 frame is loaded.
lidar TTC: 8.30978
FAST detector and ORB descriptor result in camera TTC: 14.7789
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
FAST detector and FREAK descriptor result in camera TTC: 11.9068
3 frame is loaded.
lidar TTC: 12.264
FAST detector and FREAK descriptor result in camera TTC: 18.7753
4 frame is loaded.
lidar TTC: 13.9161
FAST detector and FREAK descriptor result in camera TTC: 12.827
5 frame is loaded.
lidar TTC: 7.11572
FAST detector and FREAK descriptor result in camera TTC: 20.3844
6 frame is loaded.
lidar TTC: 16.2511
FAST detector and FREAK descriptor result in camera TTC: 26.6419
7 frame is loaded.
lidar TTC: 12.4213
FAST detector and FREAK descriptor result in camera TTC: 13.4184
8 frame is loaded.
lidar TTC: 34.3404
FAST detector and FREAK descriptor result in camera TTC: 13.8976
9 frame is loaded.
lidar TTC: 9.34376
FAST detector and FREAK descriptor result in camera TTC: 11.7407
10 frame is loaded.
lidar TTC: 18.1318
FAST detector and FREAK descriptor result in camera TTC: 14.7095
11 frame is loaded.
lidar TTC: 18.0318
FAST detector and FREAK descriptor result in camera TTC: 15.1022
12 frame is loaded.
lidar TTC: 3.83244
FAST detector and FREAK descriptor result in camera TTC: 15.7999
13 frame is loaded.
lidar TTC: nan
FAST detector and FREAK descriptor result in camera TTC: 11.6383
14 frame is loaded.
lidar TTC: 9.22307
FAST detector and FREAK descriptor result in camera TTC: 11.2609
15 frame is loaded.
lidar TTC: 10.9678
FAST detector and FREAK descriptor result in camera TTC: 10.4143
16 frame is loaded.
lidar TTC: 8.09422
FAST detector and FREAK descriptor result in camera TTC: 12.0525
17 frame is loaded.
lidar TTC: 3.17535
FAST detector and FREAK descriptor result in camera TTC: 11.6067
18 frame is loaded.
lidar TTC: nan
FAST detector and FREAK descriptor result in camera TTC: 8.15927
19 frame is loaded.
lidar TTC: 8.30978
FAST detector and FREAK descriptor result in camera TTC: 11.7376
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
FAST detector and SIFT descriptor result in camera TTC: 13.5298
3 frame is loaded.
lidar TTC: 12.264
FAST detector and SIFT descriptor result in camera TTC: 20.8149
4 frame is loaded.
lidar TTC: 13.9161
FAST detector and SIFT descriptor result in camera TTC: 24.093
5 frame is loaded.
lidar TTC: 7.11572
FAST detector and SIFT descriptor result in camera TTC: 17.1294
6 frame is loaded.
lidar TTC: 16.2511
FAST detector and SIFT descriptor result in camera TTC: 27.0679
7 frame is loaded.
lidar TTC: 12.4213
FAST detector and SIFT descriptor result in camera TTC: 21.7336
8 frame is loaded.
lidar TTC: 34.3404
FAST detector and SIFT descriptor result in camera TTC: 14.9275
9 frame is loaded.
lidar TTC: 9.34376
FAST detector and SIFT descriptor result in camera TTC: 15.2698
10 frame is loaded.
lidar TTC: 18.1318
FAST detector and SIFT descriptor result in camera TTC: 16.7693
11 frame is loaded.
lidar TTC: 18.0318
FAST detector and SIFT descriptor result in camera TTC: 16.8124
12 frame is loaded.
lidar TTC: 3.83244
FAST detector and SIFT descriptor result in camera TTC: 20.4478
13 frame is loaded.
lidar TTC: nan
FAST detector and SIFT descriptor result in camera TTC: 13.615
14 frame is loaded.
lidar TTC: 9.22307
FAST detector and SIFT descriptor result in camera TTC: 13.7808
15 frame is loaded.
lidar TTC: 10.9678
FAST detector and SIFT descriptor result in camera TTC: 15.0352
16 frame is loaded.
lidar TTC: 8.09422
FAST detector and SIFT descriptor result in camera TTC: 13.6294
17 frame is loaded.
lidar TTC: 3.17535
FAST detector and SIFT descriptor result in camera TTC: 13.293
18 frame is loaded.
lidar TTC: nan
FAST detector and SIFT descriptor result in camera TTC: 9.77937
19 frame is loaded.
lidar TTC: 8.30978
FAST detector and SIFT descriptor result in camera TTC: 11.7322
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
BRISK detector and BRIEF descriptor result in camera TTC: 17.3717
3 frame is loaded.
lidar TTC: 12.264
BRISK detector and BRIEF descriptor result in camera TTC: 19.5919
4 frame is loaded.
lidar TTC: 13.9161
BRISK detector and BRIEF descriptor result in camera TTC: 14.3366
5 frame is loaded.
lidar TTC: 7.11572
BRISK detector and BRIEF descriptor result in camera TTC: 23.1939
6 frame is loaded.
lidar TTC: 16.2511
BRISK detector and BRIEF descriptor result in camera TTC: 15.0807
7 frame is loaded.
lidar TTC: 12.4213
BRISK detector and BRIEF descriptor result in camera TTC: 19.124
8 frame is loaded.
lidar TTC: 34.3404
BRISK detector and BRIEF descriptor result in camera TTC: 20.1569
9 frame is loaded.
lidar TTC: 9.34376
BRISK detector and BRIEF descriptor result in camera TTC: 20.1422
10 frame is loaded.
lidar TTC: 18.1318
BRISK detector and BRIEF descriptor result in camera TTC: 17.8055
11 frame is loaded.
lidar TTC: 18.0318
BRISK detector and BRIEF descriptor result in camera TTC: 15.2938
12 frame is loaded.
lidar TTC: 3.83244
BRISK detector and BRIEF descriptor result in camera TTC: 15.5647
13 frame is loaded.
lidar TTC: nan
BRISK detector and BRIEF descriptor result in camera TTC: 17.8875
14 frame is loaded.
lidar TTC: 9.22307
BRISK detector and BRIEF descriptor result in camera TTC: 14.5418
15 frame is loaded.
lidar TTC: 10.9678
BRISK detector and BRIEF descriptor result in camera TTC: 14.9573
16 frame is loaded.
lidar TTC: 8.09422
BRISK detector and BRIEF descriptor result in camera TTC: 11.6865
17 frame is loaded.
lidar TTC: 3.17535
BRISK detector and BRIEF descriptor result in camera TTC: 14.8094
18 frame is loaded.
lidar TTC: nan
BRISK detector and BRIEF descriptor result in camera TTC: 12.8626
19 frame is loaded.
lidar TTC: 8.30978
BRISK detector and BRIEF descriptor result in camera TTC: 15.8866
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
BRISK detector and ORB descriptor result in camera TTC: 16.9141
3 frame is loaded.
lidar TTC: 12.264
BRISK detector and ORB descriptor result in camera TTC: 20.0254
4 frame is loaded.
lidar TTC: 13.9161
BRISK detector and ORB descriptor result in camera TTC: 16.6348
5 frame is loaded.
lidar TTC: 7.11572
BRISK detector and ORB descriptor result in camera TTC: 16.9104
6 frame is loaded.
lidar TTC: 16.2511
BRISK detector and ORB descriptor result in camera TTC: 19.5731
7 frame is loaded.
lidar TTC: 12.4213
BRISK detector and ORB descriptor result in camera TTC: 22.3442
8 frame is loaded.
lidar TTC: 34.3404
BRISK detector and ORB descriptor result in camera TTC: 16.4015
9 frame is loaded.
lidar TTC: 9.34376
BRISK detector and ORB descriptor result in camera TTC: 14.5313
10 frame is loaded.
lidar TTC: 18.1318
BRISK detector and ORB descriptor result in camera TTC: 16.4172
11 frame is loaded.
lidar TTC: 18.0318
BRISK detector and ORB descriptor result in camera TTC: 12.076
12 frame is loaded.
lidar TTC: 3.83244
BRISK detector and ORB descriptor result in camera TTC: 16.8371
13 frame is loaded.
lidar TTC: nan
BRISK detector and ORB descriptor result in camera TTC: 13.8712
14 frame is loaded.
lidar TTC: 9.22307
BRISK detector and ORB descriptor result in camera TTC: 10.8675
15 frame is loaded.
lidar TTC: 10.9678
BRISK detector and ORB descriptor result in camera TTC: 13.8459
16 frame is loaded.
lidar TTC: 8.09422
BRISK detector and ORB descriptor result in camera TTC: 11.6838
17 frame is loaded.
lidar TTC: 3.17535
BRISK detector and ORB descriptor result in camera TTC: 11.7846
18 frame is loaded.
lidar TTC: nan
BRISK detector and ORB descriptor result in camera TTC: 11.286
19 frame is loaded.
lidar TTC: 8.30978
BRISK detector and ORB descriptor result in camera TTC: 11.8953
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
BRISK detector and FREAK descriptor result in camera TTC: 11.595
3 frame is loaded.
lidar TTC: 12.264
BRISK detector and FREAK descriptor result in camera TTC: 21.4548
4 frame is loaded.
lidar TTC: 13.9161
BRISK detector and FREAK descriptor result in camera TTC: 14.488
5 frame is loaded.
lidar TTC: 7.11572
BRISK detector and FREAK descriptor result in camera TTC: 12.6344
6 frame is loaded.
lidar TTC: 16.2511
BRISK detector and FREAK descriptor result in camera TTC: 23.9314
7 frame is loaded.
lidar TTC: 12.4213
BRISK detector and FREAK descriptor result in camera TTC: 18.8801
8 frame is loaded.
lidar TTC: 34.3404
BRISK detector and FREAK descriptor result in camera TTC: 12.3906
9 frame is loaded.
lidar TTC: 9.34376
BRISK detector and FREAK descriptor result in camera TTC: 20.0726
10 frame is loaded.
lidar TTC: 18.1318
BRISK detector and FREAK descriptor result in camera TTC: 15.847
11 frame is loaded.
lidar TTC: 18.0318
BRISK detector and FREAK descriptor result in camera TTC: 14.5502
12 frame is loaded.
lidar TTC: 3.83244
BRISK detector and FREAK descriptor result in camera TTC: 13.4912
13 frame is loaded.
lidar TTC: nan
BRISK detector and FREAK descriptor result in camera TTC: 13.2066
14 frame is loaded.
lidar TTC: 9.22307
BRISK detector and FREAK descriptor result in camera TTC: 12.9163
15 frame is loaded.
lidar TTC: 10.9678
BRISK detector and FREAK descriptor result in camera TTC: 12.8786
16 frame is loaded.
lidar TTC: 8.09422
BRISK detector and FREAK descriptor result in camera TTC: 15.5123
17 frame is loaded.
lidar TTC: 3.17535
BRISK detector and FREAK descriptor result in camera TTC: 10.7897
18 frame is loaded.
lidar TTC: nan
BRISK detector and FREAK descriptor result in camera TTC: 8.53323
19 frame is loaded.
lidar TTC: 8.30978
BRISK detector and FREAK descriptor result in camera TTC: 10.793
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
BRISK detector and SIFT descriptor result in camera TTC: 14.992
3 frame is loaded.
lidar TTC: 12.264
BRISK detector and SIFT descriptor result in camera TTC: 16.7399
4 frame is loaded.
lidar TTC: 13.9161
BRISK detector and SIFT descriptor result in camera TTC: 17.5077
5 frame is loaded.
lidar TTC: 7.11572
BRISK detector and SIFT descriptor result in camera TTC: 13.8644
6 frame is loaded.
lidar TTC: 16.2511
BRISK detector and SIFT descriptor result in camera TTC: 87.5917
7 frame is loaded.
lidar TTC: 12.4213
BRISK detector and SIFT descriptor result in camera TTC: 17.3844
8 frame is loaded.
lidar TTC: 34.3404
BRISK detector and SIFT descriptor result in camera TTC: 13.1985
9 frame is loaded.
lidar TTC: 9.34376
BRISK detector and SIFT descriptor result in camera TTC: 17.8964
10 frame is loaded.
lidar TTC: 18.1318
BRISK detector and SIFT descriptor result in camera TTC: 17.1342
11 frame is loaded.
lidar TTC: 18.0318
BRISK detector and SIFT descriptor result in camera TTC: 15.8737
12 frame is loaded.
lidar TTC: 3.83244
BRISK detector and SIFT descriptor result in camera TTC: 14.1432
13 frame is loaded.
lidar TTC: nan
BRISK detector and SIFT descriptor result in camera TTC: 11.012
14 frame is loaded.
lidar TTC: 9.22307
BRISK detector and SIFT descriptor result in camera TTC: 16.2202
15 frame is loaded.
lidar TTC: 10.9678
BRISK detector and SIFT descriptor result in camera TTC: 12.2993
16 frame is loaded.
lidar TTC: 8.09422
BRISK detector and SIFT descriptor result in camera TTC: 14.5894
17 frame is loaded.
lidar TTC: 3.17535
BRISK detector and SIFT descriptor result in camera TTC: 12.5363
18 frame is loaded.
lidar TTC: nan
BRISK detector and SIFT descriptor result in camera TTC: 13.354
19 frame is loaded.
lidar TTC: 8.30978
BRISK detector and SIFT descriptor result in camera TTC: 13.5795
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
ORB detector and BRIEF descriptor result in camera TTC: 23.0111
3 frame is loaded.
lidar TTC: 12.264
ORB detector and BRIEF descriptor result in camera TTC: 168.288
4 frame is loaded.
lidar TTC: 13.9161
ORB detector and BRIEF descriptor result in camera TTC: 91.6169
5 frame is loaded.
lidar TTC: 7.11572
ORB detector and BRIEF descriptor result in camera TTC: 12.7012
6 frame is loaded.
lidar TTC: 16.2511
ORB detector and BRIEF descriptor result in camera TTC: 16.6984
7 frame is loaded.
lidar TTC: 12.4213
ORB detector and BRIEF descriptor result in camera TTC: 21.9452
8 frame is loaded.
lidar TTC: 34.3404
ORB detector and BRIEF descriptor result in camera TTC: 46.3772
9 frame is loaded.
lidar TTC: 9.34376
ORB detector and BRIEF descriptor result in camera TTC: 28.7208
10 frame is loaded.
lidar TTC: 18.1318
ORB detector and BRIEF descriptor result in camera TTC: 32.9072
11 frame is loaded.
lidar TTC: 18.0318
ORB detector and BRIEF descriptor result in camera TTC: 19.3673
12 frame is loaded.
lidar TTC: 3.83244
ORB detector and BRIEF descriptor result in camera TTC: 18.754
13 frame is loaded.
lidar TTC: nan
ORB detector and BRIEF descriptor result in camera TTC: 19.8664
14 frame is loaded.
lidar TTC: 9.22307
ORB detector and BRIEF descriptor result in camera TTC: 18.9238
15 frame is loaded.
lidar TTC: 10.9678
ORB detector and BRIEF descriptor result in camera TTC: 14.5375
16 frame is loaded.
lidar TTC: 8.09422
ORB detector and BRIEF descriptor result in camera TTC: 13.5951
17 frame is loaded.
lidar TTC: 3.17535
ORB detector and BRIEF descriptor result in camera TTC: 12.5568
18 frame is loaded.
lidar TTC: nan
ORB detector and BRIEF descriptor result in camera TTC: 17.0445
19 frame is loaded.
lidar TTC: 8.30978
ORB detector and BRIEF descriptor result in camera TTC: 17.7293
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
ORB detector and ORB descriptor result in camera TTC: 33.7129
3 frame is loaded.
lidar TTC: 12.264
ORB detector and ORB descriptor result in camera TTC: 13.2967
4 frame is loaded.
lidar TTC: 13.9161
ORB detector and ORB descriptor result in camera TTC: 15.5098
5 frame is loaded.
lidar TTC: 7.11572
ORB detector and ORB descriptor result in camera TTC: 31.6381
6 frame is loaded.
lidar TTC: 16.2511
ORB detector and ORB descriptor result in camera TTC: 51.6484
7 frame is loaded.
lidar TTC: 12.4213
ORB detector and ORB descriptor result in camera TTC: 13.9743
8 frame is loaded.
lidar TTC: 34.3404
ORB detector and ORB descriptor result in camera TTC: 34.6812
9 frame is loaded.
lidar TTC: 9.34376
ORB detector and ORB descriptor result in camera TTC: 15.0575
10 frame is loaded.
lidar TTC: 18.1318
ORB detector and ORB descriptor result in camera TTC: 36.1654
11 frame is loaded.
lidar TTC: 18.0318
ORB detector and ORB descriptor result in camera TTC: 62.3751
12 frame is loaded.
lidar TTC: 3.83244
ORB detector and ORB descriptor result in camera TTC: 9.26264
13 frame is loaded.
lidar TTC: nan
ORB detector and ORB descriptor result in camera TTC: 62.2448
14 frame is loaded.
lidar TTC: 9.22307
ORB detector and ORB descriptor result in camera TTC: 17.6718
15 frame is loaded.
lidar TTC: 10.9678
ORB detector and ORB descriptor result in camera TTC: 42.7517
16 frame is loaded.
lidar TTC: 8.09422
ORB detector and ORB descriptor result in camera TTC: 21.167
17 frame is loaded.
lidar TTC: 3.17535
ORB detector and ORB descriptor result in camera TTC: 18.2076
18 frame is loaded.
lidar TTC: nan
ORB detector and ORB descriptor result in camera TTC: 10.8735
19 frame is loaded.
lidar TTC: 8.30978
ORB detector and ORB descriptor result in camera TTC: 22.8144
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
ORB detector and FREAK descriptor result in camera TTC: 13.4849
3 frame is loaded.
lidar TTC: 12.264
ORB detector and FREAK descriptor result in camera TTC: 24.1036
4 frame is loaded.
lidar TTC: 13.9161
ORB detector and FREAK descriptor result in camera TTC: 17.9715
5 frame is loaded.
lidar TTC: 7.11572
ORB detector and FREAK descriptor result in camera TTC: 13.129
6 frame is loaded.
lidar TTC: 16.2511
ORB detector and FREAK descriptor result in camera TTC: 149.075
7 frame is loaded.
lidar TTC: 12.4213
ORB detector and FREAK descriptor result in camera TTC: 15.4253
8 frame is loaded.
lidar TTC: 34.3404
ORB detector and FREAK descriptor result in camera TTC: -231.137
9 frame is loaded.
lidar TTC: 9.34376
ORB detector and FREAK descriptor result in camera TTC: 9.55137
10 frame is loaded.
lidar TTC: 18.1318
ORB detector and FREAK descriptor result in camera TTC: 16.6074
11 frame is loaded.
lidar TTC: 18.0318
ORB detector and FREAK descriptor result in camera TTC: -167.62
12 frame is loaded.
lidar TTC: 3.83244
ORB detector and FREAK descriptor result in camera TTC: 7.44254
13 frame is loaded.
lidar TTC: nan
ORB detector and FREAK descriptor result in camera TTC: 31.0825
14 frame is loaded.
lidar TTC: 9.22307
ORB detector and FREAK descriptor result in camera TTC: 6.69146
15 frame is loaded.
lidar TTC: 10.9678
ORB detector and FREAK descriptor result in camera TTC: 49.6542
16 frame is loaded.
lidar TTC: 8.09422
ORB detector and FREAK descriptor result in camera TTC: 9.45089
17 frame is loaded.
lidar TTC: 3.17535
ORB detector and FREAK descriptor result in camera TTC: 9.77878
18 frame is loaded.
lidar TTC: nan
ORB detector and FREAK descriptor result in camera TTC: 14.8767
19 frame is loaded.
lidar TTC: 8.30978
ORB detector and FREAK descriptor result in camera TTC: 8.87524
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
ORB detector and SIFT descriptor result in camera TTC: 20.2463
3 frame is loaded.
lidar TTC: 12.264
ORB detector and SIFT descriptor result in camera TTC: 16.8423
4 frame is loaded.
lidar TTC: 13.9161
ORB detector and SIFT descriptor result in camera TTC: 15.1039
5 frame is loaded.
lidar TTC: 7.11572
ORB detector and SIFT descriptor result in camera TTC: 83.6445
6 frame is loaded.
lidar TTC: 16.2511
ORB detector and SIFT descriptor result in camera TTC: 22.6349
7 frame is loaded.
lidar TTC: 12.4213
ORB detector and SIFT descriptor result in camera TTC: 15.5311
8 frame is loaded.
lidar TTC: 34.3404
ORB detector and SIFT descriptor result in camera TTC: 17.3471
9 frame is loaded.
lidar TTC: 9.34376
ORB detector and SIFT descriptor result in camera TTC: 12.7725
10 frame is loaded.
lidar TTC: 18.1318
ORB detector and SIFT descriptor result in camera TTC: 15.5031
11 frame is loaded.
lidar TTC: 18.0318
ORB detector and SIFT descriptor result in camera TTC: 19.2323
12 frame is loaded.
lidar TTC: 3.83244
ORB detector and SIFT descriptor result in camera TTC: 8.42848
13 frame is loaded.
lidar TTC: nan
ORB detector and SIFT descriptor result in camera TTC: 18.8758
14 frame is loaded.
lidar TTC: 9.22307
ORB detector and SIFT descriptor result in camera TTC: 9.75272
15 frame is loaded.
lidar TTC: 10.9678
ORB detector and SIFT descriptor result in camera TTC: 13.7795
16 frame is loaded.
lidar TTC: 8.09422
ORB detector and SIFT descriptor result in camera TTC: 20.0122
17 frame is loaded.
lidar TTC: 3.17535
ORB detector and SIFT descriptor result in camera TTC: 9.87884
18 frame is loaded.
lidar TTC: nan
ORB detector and SIFT descriptor result in camera TTC: 12.3907
19 frame is loaded.
lidar TTC: 8.30978
ORB detector and SIFT descriptor result in camera TTC: 13.6967
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
AKAZE detector and BRIEF descriptor result in camera TTC: 16.2242
3 frame is loaded.
lidar TTC: 12.264
AKAZE detector and BRIEF descriptor result in camera TTC: 16.0032
4 frame is loaded.
lidar TTC: 13.9161
AKAZE detector and BRIEF descriptor result in camera TTC: 15.9452
5 frame is loaded.
lidar TTC: 7.11572
AKAZE detector and BRIEF descriptor result in camera TTC: 14.3019
6 frame is loaded.
lidar TTC: 16.2511
AKAZE detector and BRIEF descriptor result in camera TTC: 14.8947
7 frame is loaded.
lidar TTC: 12.4213
AKAZE detector and BRIEF descriptor result in camera TTC: 14.9697
8 frame is loaded.
lidar TTC: 34.3404
AKAZE detector and BRIEF descriptor result in camera TTC: 15.3358
9 frame is loaded.
lidar TTC: 9.34376
AKAZE detector and BRIEF descriptor result in camera TTC: 14.4405
10 frame is loaded.
lidar TTC: 18.1318
AKAZE detector and BRIEF descriptor result in camera TTC: 14.406
11 frame is loaded.
lidar TTC: 18.0318
AKAZE detector and BRIEF descriptor result in camera TTC: 11.6587
12 frame is loaded.
lidar TTC: 3.83244
AKAZE detector and BRIEF descriptor result in camera TTC: 13.4655
13 frame is loaded.
lidar TTC: nan
AKAZE detector and BRIEF descriptor result in camera TTC: 12.7816
14 frame is loaded.
lidar TTC: 9.22307
AKAZE detector and BRIEF descriptor result in camera TTC: 10.3925
15 frame is loaded.
lidar TTC: 10.9678
AKAZE detector and BRIEF descriptor result in camera TTC: 11.9299
16 frame is loaded.
lidar TTC: 8.09422
AKAZE detector and BRIEF descriptor result in camera TTC: 13.9401
17 frame is loaded.
lidar TTC: 3.17535
AKAZE detector and BRIEF descriptor result in camera TTC: 10.0066
18 frame is loaded.
lidar TTC: nan
AKAZE detector and BRIEF descriptor result in camera TTC: 9.89438
19 frame is loaded.
lidar TTC: 8.30978
AKAZE detector and BRIEF descriptor result in camera TTC: 10.7034
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
AKAZE detector and ORB descriptor result in camera TTC: 13.6349
3 frame is loaded.
lidar TTC: 12.264
AKAZE detector and ORB descriptor result in camera TTC: 16.9949
4 frame is loaded.
lidar TTC: 13.9161
AKAZE detector and ORB descriptor result in camera TTC: 14.8897
5 frame is loaded.
lidar TTC: 7.11572
AKAZE detector and ORB descriptor result in camera TTC: 16.805
6 frame is loaded.
lidar TTC: 16.2511
AKAZE detector and ORB descriptor result in camera TTC: 16.9829
7 frame is loaded.
lidar TTC: 12.4213
AKAZE detector and ORB descriptor result in camera TTC: 15.0935
8 frame is loaded.
lidar TTC: 34.3404
AKAZE detector and ORB descriptor result in camera TTC: 15.6288
9 frame is loaded.
lidar TTC: 9.34376
AKAZE detector and ORB descriptor result in camera TTC: 14.2676
10 frame is loaded.
lidar TTC: 18.1318
AKAZE detector and ORB descriptor result in camera TTC: 14.1106
11 frame is loaded.
lidar TTC: 18.0318
AKAZE detector and ORB descriptor result in camera TTC: 11.643
12 frame is loaded.
lidar TTC: 3.83244
AKAZE detector and ORB descriptor result in camera TTC: 13.1657
13 frame is loaded.
lidar TTC: nan
AKAZE detector and ORB descriptor result in camera TTC: 12.1145
14 frame is loaded.
lidar TTC: 9.22307
AKAZE detector and ORB descriptor result in camera TTC: 11.6824
15 frame is loaded.
lidar TTC: 10.9678
AKAZE detector and ORB descriptor result in camera TTC: 11.3698
16 frame is loaded.
lidar TTC: 8.09422
AKAZE detector and ORB descriptor result in camera TTC: 11.6217
17 frame is loaded.
lidar TTC: 3.17535
AKAZE detector and ORB descriptor result in camera TTC: 8.83796
18 frame is loaded.
lidar TTC: nan
AKAZE detector and ORB descriptor result in camera TTC: 9.81592
19 frame is loaded.
lidar TTC: 8.30978
AKAZE detector and ORB descriptor result in camera TTC: 10.3337
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
AKAZE detector and FREAK descriptor result in camera TTC: 12.756
3 frame is loaded.
lidar TTC: 12.264
AKAZE detector and FREAK descriptor result in camera TTC: 15.9179
4 frame is loaded.
lidar TTC: 13.9161
AKAZE detector and FREAK descriptor result in camera TTC: 16.0698
5 frame is loaded.
lidar TTC: 7.11572
AKAZE detector and FREAK descriptor result in camera TTC: 13.9034
6 frame is loaded.
lidar TTC: 16.2511
AKAZE detector and FREAK descriptor result in camera TTC: 15.7575
7 frame is loaded.
lidar TTC: 12.4213
AKAZE detector and FREAK descriptor result in camera TTC: 15.1956
8 frame is loaded.
lidar TTC: 34.3404
AKAZE detector and FREAK descriptor result in camera TTC: 15.1564
9 frame is loaded.
lidar TTC: 9.34376
AKAZE detector and FREAK descriptor result in camera TTC: 14.687
10 frame is loaded.
lidar TTC: 18.1318
AKAZE detector and FREAK descriptor result in camera TTC: 14.5476
11 frame is loaded.
lidar TTC: 18.0318
AKAZE detector and FREAK descriptor result in camera TTC: 11.628
12 frame is loaded.
lidar TTC: 3.83244
AKAZE detector and FREAK descriptor result in camera TTC: 12.506
13 frame is loaded.
lidar TTC: nan
AKAZE detector and FREAK descriptor result in camera TTC: 11.9384
14 frame is loaded.
lidar TTC: 9.22307
AKAZE detector and FREAK descriptor result in camera TTC: 11.2297
15 frame is loaded.
lidar TTC: 10.9678
AKAZE detector and FREAK descriptor result in camera TTC: 10.0264
16 frame is loaded.
lidar TTC: 8.09422
AKAZE detector and FREAK descriptor result in camera TTC: 11.2537
17 frame is loaded.
lidar TTC: 3.17535
AKAZE detector and FREAK descriptor result in camera TTC: 10.5666
18 frame is loaded.
lidar TTC: nan
AKAZE detector and FREAK descriptor result in camera TTC: 9.63065
19 frame is loaded.
lidar TTC: 8.30978
AKAZE detector and FREAK descriptor result in camera TTC: 8.97085
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
AKAZE detector and AKAZE descriptor result in camera TTC: 12.441
3 frame is loaded.
lidar TTC: 12.264
AKAZE detector and AKAZE descriptor result in camera TTC: 16.8526
4 frame is loaded.
lidar TTC: 13.9161
AKAZE detector and AKAZE descriptor result in camera TTC: 12.9507
5 frame is loaded.
lidar TTC: 7.11572
AKAZE detector and AKAZE descriptor result in camera TTC: 14.9597
6 frame is loaded.
lidar TTC: 16.2511
AKAZE detector and AKAZE descriptor result in camera TTC: 20.9921
7 frame is loaded.
lidar TTC: 12.4213
AKAZE detector and AKAZE descriptor result in camera TTC: 14.5715
8 frame is loaded.
lidar TTC: 34.3404
AKAZE detector and AKAZE descriptor result in camera TTC: 15.7043
9 frame is loaded.
lidar TTC: 9.34376
AKAZE detector and AKAZE descriptor result in camera TTC: 14.3474
10 frame is loaded.
lidar TTC: 18.1318
AKAZE detector and AKAZE descriptor result in camera TTC: 14.5826
11 frame is loaded.
lidar TTC: 18.0318
AKAZE detector and AKAZE descriptor result in camera TTC: 11.7256
12 frame is loaded.
lidar TTC: 3.83244
AKAZE detector and AKAZE descriptor result in camera TTC: 12.6188
13 frame is loaded.
lidar TTC: nan
AKAZE detector and AKAZE descriptor result in camera TTC: 11.9552
14 frame is loaded.
lidar TTC: 9.22307
AKAZE detector and AKAZE descriptor result in camera TTC: 12.2001
15 frame is loaded.
lidar TTC: 10.9678
AKAZE detector and AKAZE descriptor result in camera TTC: 11.9151
16 frame is loaded.
lidar TTC: 8.09422
AKAZE detector and AKAZE descriptor result in camera TTC: 13.0421
17 frame is loaded.
lidar TTC: 3.17535
AKAZE detector and AKAZE descriptor result in camera TTC: 10.7726
18 frame is loaded.
lidar TTC: nan
AKAZE detector and AKAZE descriptor result in camera TTC: 9.89446
19 frame is loaded.
lidar TTC: 8.30978
AKAZE detector and AKAZE descriptor result in camera TTC: 9.89843
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
AKAZE detector and SIFT descriptor result in camera TTC: 12.9555
3 frame is loaded.
lidar TTC: 12.264
AKAZE detector and SIFT descriptor result in camera TTC: 16.5437
4 frame is loaded.
lidar TTC: 13.9161
AKAZE detector and SIFT descriptor result in camera TTC: 14.1958
5 frame is loaded.
lidar TTC: 7.11572
AKAZE detector and SIFT descriptor result in camera TTC: 15.3166
6 frame is loaded.
lidar TTC: 16.2511
AKAZE detector and SIFT descriptor result in camera TTC: 17.1669
7 frame is loaded.
lidar TTC: 12.4213
AKAZE detector and SIFT descriptor result in camera TTC: 15.8189
8 frame is loaded.
lidar TTC: 34.3404
AKAZE detector and SIFT descriptor result in camera TTC: 15.3966
9 frame is loaded.
lidar TTC: 9.34376
AKAZE detector and SIFT descriptor result in camera TTC: 13.8732
10 frame is loaded.
lidar TTC: 18.1318
AKAZE detector and SIFT descriptor result in camera TTC: 14.5297
11 frame is loaded.
lidar TTC: 18.0318
AKAZE detector and SIFT descriptor result in camera TTC: 11.8362
12 frame is loaded.
lidar TTC: 3.83244
AKAZE detector and SIFT descriptor result in camera TTC: 12.8055
13 frame is loaded.
lidar TTC: nan
AKAZE detector and SIFT descriptor result in camera TTC: 12.0003
14 frame is loaded.
lidar TTC: 9.22307
AKAZE detector and SIFT descriptor result in camera TTC: 11.8158
15 frame is loaded.
lidar TTC: 10.9678
AKAZE detector and SIFT descriptor result in camera TTC: 11.9425
16 frame is loaded.
lidar TTC: 8.09422
AKAZE detector and SIFT descriptor result in camera TTC: 13.5786
17 frame is loaded.
lidar TTC: 3.17535
AKAZE detector and SIFT descriptor result in camera TTC: 10.0323
18 frame is loaded.
lidar TTC: nan
AKAZE detector and SIFT descriptor result in camera TTC: 9.83797
19 frame is loaded.
lidar TTC: 8.30978
AKAZE detector and SIFT descriptor result in camera TTC: 10.4334
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
SIFT detector and BRIEF descriptor result in camera TTC: 11.942
3 frame is loaded.
lidar TTC: 12.264
SIFT detector and BRIEF descriptor result in camera TTC: 12.9422
4 frame is loaded.
lidar TTC: 13.9161
SIFT detector and BRIEF descriptor result in camera TTC: 16.1889
5 frame is loaded.
lidar TTC: 7.11572
SIFT detector and BRIEF descriptor result in camera TTC: 24.669
6 frame is loaded.
lidar TTC: 16.2511
SIFT detector and BRIEF descriptor result in camera TTC: 15.097
7 frame is loaded.
lidar TTC: 12.4213
SIFT detector and BRIEF descriptor result in camera TTC: 10.1629
8 frame is loaded.
lidar TTC: 34.3404
SIFT detector and BRIEF descriptor result in camera TTC: 19.2115
9 frame is loaded.
lidar TTC: 9.34376
SIFT detector and BRIEF descriptor result in camera TTC: 17.2787
10 frame is loaded.
lidar TTC: 18.1318
SIFT detector and BRIEF descriptor result in camera TTC: 12.9027
11 frame is loaded.
lidar TTC: 18.0318
SIFT detector and BRIEF descriptor result in camera TTC: 9.94662
12 frame is loaded.
lidar TTC: 3.83244
SIFT detector and BRIEF descriptor result in camera TTC: 12.8971
13 frame is loaded.
lidar TTC: nan
SIFT detector and BRIEF descriptor result in camera TTC: 9.40367
14 frame is loaded.
lidar TTC: 9.22307
SIFT detector and BRIEF descriptor result in camera TTC: 10.3986
15 frame is loaded.
lidar TTC: 10.9678
SIFT detector and BRIEF descriptor result in camera TTC: 10.4928
16 frame is loaded.
lidar TTC: 8.09422
SIFT detector and BRIEF descriptor result in camera TTC: 10.4246
17 frame is loaded.
lidar TTC: 3.17535
SIFT detector and BRIEF descriptor result in camera TTC: 9.83702
18 frame is loaded.
lidar TTC: nan
SIFT detector and BRIEF descriptor result in camera TTC: 9.31726
19 frame is loaded.
lidar TTC: 8.30978
SIFT detector and BRIEF descriptor result in camera TTC: 9.04508
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
SIFT detector and FREAK descriptor result in camera TTC: 10.381
3 frame is loaded.
lidar TTC: 12.264
SIFT detector and FREAK descriptor result in camera TTC: 13.3977
4 frame is loaded.
lidar TTC: 13.9161
SIFT detector and FREAK descriptor result in camera TTC: 12.8489
5 frame is loaded.
lidar TTC: 7.11572
SIFT detector and FREAK descriptor result in camera TTC: 22.4599
6 frame is loaded.
lidar TTC: 16.2511
SIFT detector and FREAK descriptor result in camera TTC: 15.2616
7 frame is loaded.
lidar TTC: 12.4213
SIFT detector and FREAK descriptor result in camera TTC: 12.1999
8 frame is loaded.
lidar TTC: 34.3404
SIFT detector and FREAK descriptor result in camera TTC: 14.4879
9 frame is loaded.
lidar TTC: 9.34376
SIFT detector and FREAK descriptor result in camera TTC: 9.3531
10 frame is loaded.
lidar TTC: 18.1318
SIFT detector and FREAK descriptor result in camera TTC: 14.3296
11 frame is loaded.
lidar TTC: 18.0318
SIFT detector and FREAK descriptor result in camera TTC: 9.69917
12 frame is loaded.
lidar TTC: 3.83244
SIFT detector and FREAK descriptor result in camera TTC: 12.1887
13 frame is loaded.
lidar TTC: nan
SIFT detector and FREAK descriptor result in camera TTC: 11.4599
14 frame is loaded.
lidar TTC: 9.22307
SIFT detector and FREAK descriptor result in camera TTC: 10.5647
15 frame is loaded.
lidar TTC: 10.9678
SIFT detector and FREAK descriptor result in camera TTC: 9.90704
16 frame is loaded.
lidar TTC: 8.09422
SIFT detector and FREAK descriptor result in camera TTC: 9.62116
17 frame is loaded.
lidar TTC: 3.17535
SIFT detector and FREAK descriptor result in camera TTC: 9.0856
18 frame is loaded.
lidar TTC: nan
SIFT detector and FREAK descriptor result in camera TTC: 9.17303
19 frame is loaded.
lidar TTC: 8.30978
SIFT detector and FREAK descriptor result in camera TTC: 9.7874
1 frame is loaded.
2 frame is loaded.
lidar TTC: 12.9722
SIFT detector and SIFT descriptor result in camera TTC: 10.6491
3 frame is loaded.
lidar TTC: 12.264
SIFT detector and SIFT descriptor result in camera TTC: 11.7585
4 frame is loaded.
lidar TTC: 13.9161
SIFT detector and SIFT descriptor result in camera TTC: 12.4266
5 frame is loaded.
lidar TTC: 7.11572
SIFT detector and SIFT descriptor result in camera TTC: 21.195
6 frame is loaded.
lidar TTC: 16.2511
SIFT detector and SIFT descriptor result in camera TTC: 12.9599
7 frame is loaded.
lidar TTC: 12.4213
SIFT detector and SIFT descriptor result in camera TTC: 10.9195
8 frame is loaded.
lidar TTC: 34.3404
SIFT detector and SIFT descriptor result in camera TTC: 12.7796
9 frame is loaded.
lidar TTC: 9.34376
SIFT detector and SIFT descriptor result in camera TTC: 14.1782
10 frame is loaded.
lidar TTC: 18.1318
SIFT detector and SIFT descriptor result in camera TTC: 11.7881
11 frame is loaded.
lidar TTC: 18.0318
SIFT detector and SIFT descriptor result in camera TTC: 11.8813
12 frame is loaded.
lidar TTC: 3.83244
SIFT detector and SIFT descriptor result in camera TTC: 10.7181
13 frame is loaded.
lidar TTC: nan
SIFT detector and SIFT descriptor result in camera TTC: 11.4758
14 frame is loaded.
lidar TTC: 9.22307
SIFT detector and SIFT descriptor result in camera TTC: 9.59551
15 frame is loaded.
lidar TTC: 10.9678
SIFT detector and SIFT descriptor result in camera TTC: 10.3136
16 frame is loaded.
lidar TTC: 8.09422
SIFT detector and SIFT descriptor result in camera TTC: 10.0235
17 frame is loaded.
lidar TTC: 3.17535
SIFT detector and SIFT descriptor result in camera TTC: 9.52937
18 frame is loaded.
lidar TTC: nan
SIFT detector and SIFT descriptor result in camera TTC: 9.57871
19 frame is loaded.
lidar TTC: 8.30978
SIFT detector and SIFT descriptor result in camera TTC: 9.31176
``````
