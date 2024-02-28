## MP1
the buffer size is checked, the element at the front will be remove as long as size limit is reached. code please see MidTermProject_Camera_Student.cpp line 68-71

## MP2
each detector can be called with function detKeypointsModern with input parameter of detector type. code please see matching2D_Student.cpp

## MP3
the coordinates of keypoints are checked against the rect boundaries, if outside then the point with be removed from the vector. code please see MidTermProject_Camera_Student.cpp line 95-105

## MP4
each descriptor can be called with function descKeypoints with input parameter of descriptor type. code please see matching2D_Student.cpp

## MP5
selector and matcher type are defined as input parameter of function matchDescriptors.
codes are implemented in line 35-39 in matching2D_Student.cpp

## MP6
selection of good matches are made with ratio of 0.8 in line 40-47 in matching2D_Student.cpp

## MP 7
1) SHITOMASI
SHITOMASI detection with n=127 keypoints in 21.5006 ms
SHITOMASI detection with n=120 keypoints in 11.7176 ms
SHITOMASI detection with n=123 keypoints in 15.9335 ms
SHITOMASI detection with n=120 keypoints in 13.8269 ms
SHITOMASI detection with n=120 keypoints in 15.6603 ms
SHITOMASI detection with n=115 keypoints in 14.8106 ms
SHITOMASI detection with n=114 keypoints in 14.4881 ms
SHITOMASI detection with n=125 keypoints in 13.7165 ms
SHITOMASI detection with n=112 keypoints in 12.0866 ms
SHITOMASI detection with n=113 keypoints in 12.3469 ms
2)HARRIS
HARRIS detection with n=50 keypoints in 16.1137 ms
HARRIS detection with n=54 keypoints in 11.5018 ms
HARRIS detection with n=53 keypoints in 7.41577 ms
HARRIS detection with n=55 keypoints in 8.48087 ms
HARRIS detection with n=56 keypoints in 7.48282 ms
HARRIS detection with n=58 keypoints in 6.30427 ms
HARRIS detection with n=57 keypoints in 8.5354 ms
HARRIS detection with n=61 keypoints in 7.09581 ms
HARRIS detection with n=60 keypoints in 8.35606 ms
HARRIS detection with n=57 keypoints in 6.42476 ms
3) FAST
FAST detection with n=149 keypoints in 6.34895 ms
FAST detection with n=152 keypoints in 2.86733 ms
FAST detection with n=152 keypoints in 1.54705 ms
FAST detection with n=157 keypoints in 1.68088 ms
FAST detection with n=149 keypoints in 1.96158 ms
FAST detection with n=150 keypoints in 1.81688 ms
FAST detection with n=157 keypoints in 1.41207 ms
FAST detection with n=152 keypoints in 1.82138 ms
FAST detection with n=139 keypoints in 1.88809 ms
FAST detection with n=144 keypoints in 1.90634 ms
4) BRISK
BRISK detection with n=254 keypoints in 81.9985 ms
BRISK detection with n=274 keypoints in 78.0637 ms
BRISK detection with n=276 keypoints in 74.8972 ms
BRISK detection with n=275 keypoints in 76.0812 ms
BRISK detection with n=293 keypoints in 79.7994 ms
BRISK detection with n=275 keypoints in 73.4593 ms
BRISK detection with n=289 keypoints in 74.7198 ms
BRISK detection with n=268 keypoints in 80.6479 ms
BRISK detection with n=260 keypoints in 72.7864 ms
BRISK detection with n=250 keypoints in 72.7695 ms
5) ORB
ORB detection with n=91 keypoints in 161.326 ms
ORB detection with n=102 keypoints in 8.15313 ms
ORB detection with n=106 keypoints in 7.44198 ms
ORB detection with n=113 keypoints in 14.6844 ms
ORB detection with n=109 keypoints in 7.51282 ms
ORB detection with n=124 keypoints in 7.1846 ms
ORB detection with n=129 keypoints in 7.93734 ms
ORB detection with n=127 keypoints in 7.01244 ms
ORB detection with n=124 keypoints in 10.8726 ms
ORB detection with n=125 keypoints in 7.21048 ms
6) AKAZE
AKAZE detection with n=162 keypoints in 72.4078 ms
AKAZE detection with n=157 keypoints in 58.7854 ms
AKAZE detection with n=159 keypoints in 61.4444 ms
AKAZE detection with n=154 keypoints in 57.8537 ms
AKAZE detection with n=162 keypoints in 53.3926 ms
AKAZE detection with n=163 keypoints in 67.5903 ms
AKAZE detection with n=173 keypoints in 62.4608 ms
AKAZE detection with n=175 keypoints in 54.8779 ms
AKAZE detection with n=175 keypoints in 71.0424 ms
AKAZE detection with n=175 keypoints in 64.5898 ms
7) SIFT
SIFT detection with n=137 keypoints in 95.5349 ms
SIFT detection with n=131 keypoints in 71.9315 ms
SIFT detection with n=121 keypoints in 67.4119 ms
SIFT detection with n=135 keypoints in 62.2313 ms
SIFT detection with n=134 keypoints in 64.7906 ms
SIFT detection with n=139 keypoints in 60.6279 ms
SIFT detection with n=136 keypoints in 79.1939 ms
SIFT detection with n=147 keypoints in 77.4389 ms
SIFT detection with n=156 keypoints in 63.5958 ms
SIFT detection with n=135 keypoints in 67.7283 ms

## MP8

1)
SHITOMASI detector and BRIEF descriptor result in 118 matches.
SHITOMASI detector and BRIEF descriptor result in 111 matches.
SHITOMASI detector and BRIEF descriptor result in 104 matches.
SHITOMASI detector and BRIEF descriptor result in 101 matches.
SHITOMASI detector and BRIEF descriptor result in 104 matches.
SHITOMASI detector and BRIEF descriptor result in 102 matches.
SHITOMASI detector and BRIEF descriptor result in 101 matches.
SHITOMASI detector and BRIEF descriptor result in 110 matches.
SHITOMASI detector and BRIEF descriptor result in 102 matches.
2)
SHITOMASI detector and ORB descriptor result in 106 matches.
SHITOMASI detector and ORB descriptor result in 103 matches.
SHITOMASI detector and ORB descriptor result in 100 matches.
SHITOMASI detector and ORB descriptor result in 102 matches.
SHITOMASI detector and ORB descriptor result in 104 matches.
SHITOMASI detector and ORB descriptor result in 98 matches.
SHITOMASI detector and ORB descriptor result in 99 matches.
SHITOMASI detector and ORB descriptor result in 103 matches.
SHITOMASI detector and ORB descriptor result in 99 matches.
3)
SHITOMASI detector and FREAK descriptor result in 91 matches.
SHITOMASI detector and FREAK descriptor result in 88 matches.
SHITOMASI detector and FREAK descriptor result in 87 matches.
SHITOMASI detector and FREAK descriptor result in 89 matches.
SHITOMASI detector and FREAK descriptor result in 84 matches.
SHITOMASI detector and FREAK descriptor result in 78 matches.
SHITOMASI detector and FREAK descriptor result in 81 matches.
SHITOMASI detector and FREAK descriptor result in 85 matches.
SHITOMASI detector and FREAK descriptor result in 85 matches.
4)
SHITOMASI detector and SIFT descriptor result in 115 matches.
SHITOMASI detector and SIFT descriptor result in 109 matches.
SHITOMASI detector and SIFT descriptor result in 104 matches.
SHITOMASI detector and SIFT descriptor result in 103 matches.
SHITOMASI detector and SIFT descriptor result in 101 matches.
SHITOMASI detector and SIFT descriptor result in 101 matches.
SHITOMASI detector and SIFT descriptor result in 97 matches.
SHITOMASI detector and SIFT descriptor result in 107 matches.
SHITOMASI detector and SIFT descriptor result in 99 matches.
5)
HARRIS detector and BRIEF descriptor result in 48 matches.
HARRIS detector and BRIEF descriptor result in 49 matches.
HARRIS detector and BRIEF descriptor result in 47 matches.
HARRIS detector and BRIEF descriptor result in 51 matches.
HARRIS detector and BRIEF descriptor result in 53 matches.
HARRIS detector and BRIEF descriptor result in 49 matches.
HARRIS detector and BRIEF descriptor result in 52 matches.
HARRIS detector and BRIEF descriptor result in 56 matches.
HARRIS detector and BRIEF descriptor result in 56 matches.
6)
HARRIS detector and ORB descriptor result in 46 matches.
HARRIS detector and ORB descriptor result in 44 matches.
HARRIS detector and ORB descriptor result in 48 matches.
HARRIS detector and ORB descriptor result in 51 matches.
HARRIS detector and ORB descriptor result in 48 matches.
HARRIS detector and ORB descriptor result in 50 matches.
HARRIS detector and ORB descriptor result in 50 matches.
HARRIS detector and ORB descriptor result in 58 matches.
HARRIS detector and ORB descriptor result in 55 matches.
7)
HARRIS detector and FREAK descriptor result in 43 matches.
HARRIS detector and FREAK descriptor result in 45 matches.
HARRIS detector and FREAK descriptor result in 44 matches.
HARRIS detector and FREAK descriptor result in 40 matches.
HARRIS detector and FREAK descriptor result in 42 matches.
HARRIS detector and FREAK descriptor result in 47 matches.
HARRIS detector and FREAK descriptor result in 43 matches.
HARRIS detector and FREAK descriptor result in 48 matches.
HARRIS detector and FREAK descriptor result in 51 matches.
8)
HARRIS detector and SIFT descriptor result in 46 matches.
HARRIS detector and SIFT descriptor result in 46 matches.
HARRIS detector and SIFT descriptor result in 50 matches.
HARRIS detector and SIFT descriptor result in 52 matches.
HARRIS detector and SIFT descriptor result in 51 matches.
HARRIS detector and SIFT descriptor result in 48 matches.
HARRIS detector and SIFT descriptor result in 52 matches.
HARRIS detector and SIFT descriptor result in 59 matches.
HARRIS detector and SIFT descriptor result in 56 matches.
9)
FAST detector and BRIEF descriptor result in 119 matches.
FAST detector and BRIEF descriptor result in 129 matches.
FAST detector and BRIEF descriptor result in 122 matches.
FAST detector and BRIEF descriptor result in 126 matches.
FAST detector and BRIEF descriptor result in 109 matches.
FAST detector and BRIEF descriptor result in 124 matches.
FAST detector and BRIEF descriptor result in 132 matches.
FAST detector and BRIEF descriptor result in 125 matches.
FAST detector and BRIEF descriptor result in 120 matches.
10)
FAST detector and ORB descriptor result in 122 matches.
FAST detector and ORB descriptor result in 123 matches.
FAST detector and ORB descriptor result in 119 matches.
FAST detector and ORB descriptor result in 129 matches.
FAST detector and ORB descriptor result in 108 matches.
FAST detector and ORB descriptor result in 121 matches.
FAST detector and ORB descriptor result in 127 matches.
FAST detector and ORB descriptor result in 122 matches.
FAST detector and ORB descriptor result in 119 matches.
11)
FAST detector and FREAK descriptor result in 97 matches.
FAST detector and FREAK descriptor result in 99 matches.
FAST detector and FREAK descriptor result in 96 matches.
FAST detector and FREAK descriptor result in 99 matches.
FAST detector and FREAK descriptor result in 89 matches.
FAST detector and FREAK descriptor result in 100 matches.
FAST detector and FREAK descriptor result in 105 matches.
FAST detector and FREAK descriptor result in 99 matches.
FAST detector and FREAK descriptor result in 103 matches.
12)
FAST detector and SIFT descriptor result in 118 matches.
FAST detector and SIFT descriptor result in 122 matches.
FAST detector and SIFT descriptor result in 114 matches.
FAST detector and SIFT descriptor result in 120 matches.
FAST detector and SIFT descriptor result in 115 matches.
FAST detector and SIFT descriptor result in 119 matches.
FAST detector and SIFT descriptor result in 124 matches.
FAST detector and SIFT descriptor result in 118 matches.
FAST detector and SIFT descriptor result in 104 matches.
13)
BRISK detector and BRIEF descriptor result in 174 matches.
BRISK detector and BRIEF descriptor result in 195 matches.
BRISK detector and BRIEF descriptor result in 182 matches.
BRISK detector and BRIEF descriptor result in 177 matches.
BRISK detector and BRIEF descriptor result in 182 matches.
BRISK detector and BRIEF descriptor result in 193 matches.
BRISK detector and BRIEF descriptor result in 208 matches.
BRISK detector and BRIEF descriptor result in 186 matches.
BRISK detector and BRIEF descriptor result in 179 matches.
14)
BRISK detector and ORB descriptor result in 153 matches.
BRISK detector and ORB descriptor result in 164 matches.
BRISK detector and ORB descriptor result in 155 matches.
BRISK detector and ORB descriptor result in 165 matches.
BRISK detector and ORB descriptor result in 150 matches.
BRISK detector and ORB descriptor result in 179 matches.
BRISK detector and ORB descriptor result in 169 matches.
BRISK detector and ORB descriptor result in 174 matches.
BRISK detector and ORB descriptor result in 171 matches.
15)
BRISK detector and FREAK descriptor result in 154 matches.
BRISK detector and FREAK descriptor result in 173 matches.
BRISK detector and FREAK descriptor result in 154 matches.
BRISK detector and FREAK descriptor result in 168 matches.
BRISK detector and FREAK descriptor result in 157 matches.
BRISK detector and FREAK descriptor result in 181 matches.
BRISK detector and FREAK descriptor result in 169 matches.
BRISK detector and FREAK descriptor result in 176 matches.
BRISK detector and FREAK descriptor result in 165 matches.
16)
BRISK detector and SIFT descriptor result in 177 matches.
BRISK detector and SIFT descriptor result in 187 matches.
BRISK detector and SIFT descriptor result in 171 matches.
BRISK detector and SIFT descriptor result in 177 matches.
BRISK detector and SIFT descriptor result in 168 matches.
BRISK detector and SIFT descriptor result in 190 matches.
BRISK detector and SIFT descriptor result in 193 matches.
BRISK detector and SIFT descriptor result in 173 matches.
BRISK detector and SIFT descriptor result in 181 matches.
17)
ORB detector and BRIEF descriptor result in 49 matches.
ORB detector and BRIEF descriptor result in 43 matches.
ORB detector and BRIEF descriptor result in 45 matches.
ORB detector and BRIEF descriptor result in 59 matches.
ORB detector and BRIEF descriptor result in 53 matches.
ORB detector and BRIEF descriptor result in 76 matches.
ORB detector and BRIEF descriptor result in 67 matches.
ORB detector and BRIEF descriptor result in 83 matches.
ORB detector and BRIEF descriptor result in 65 matches.
18)
ORB detector and ORB descriptor result in 65 matches.
ORB detector and ORB descriptor result in 69 matches.
ORB detector and ORB descriptor result in 71 matches.
ORB detector and ORB descriptor result in 85 matches.
ORB detector and ORB descriptor result in 91 matches.
ORB detector and ORB descriptor result in 99 matches.
ORB detector and ORB descriptor result in 94 matches.
ORB detector and ORB descriptor result in 91 matches.
ORB detector and ORB descriptor result in 89 matches.
19)
ORB detector and FREAK descriptor result in 41 matches.
ORB detector and FREAK descriptor result in 36 matches.
ORB detector and FREAK descriptor result in 45 matches.
ORB detector and FREAK descriptor result in 47 matches.
ORB detector and FREAK descriptor result in 44 matches.
ORB detector and FREAK descriptor result in 51 matches.
ORB detector and FREAK descriptor result in 52 matches.
ORB detector and FREAK descriptor result in 48 matches.
ORB detector and FREAK descriptor result in 53 matches.
20)
ORB detector and SIFT descriptor result in 66 matches.
ORB detector and SIFT descriptor result in 79 matches.
ORB detector and SIFT descriptor result in 78 matches.
ORB detector and SIFT descriptor result in 79 matches.
ORB detector and SIFT descriptor result in 82 matches.
ORB detector and SIFT descriptor result in 93 matches.
ORB detector and SIFT descriptor result in 94 matches.
ORB detector and SIFT descriptor result in 93 matches.
ORB detector and SIFT descriptor result in 92 matches.
21)
AKAZE detector and BRIEF descriptor result in 137 matches.
AKAZE detector and BRIEF descriptor result in 133 matches.
AKAZE detector and BRIEF descriptor result in 130 matches.
AKAZE detector and BRIEF descriptor result in 130 matches.
AKAZE detector and BRIEF descriptor result in 134 matches.
AKAZE detector and BRIEF descriptor result in 146 matches.
AKAZE detector and BRIEF descriptor result in 150 matches.
AKAZE detector and BRIEF descriptor result in 147 matches.
AKAZE detector and BRIEF descriptor result in 150 matches.
22)
AKAZE detector and ORB descriptor result in 127 matches.
AKAZE detector and ORB descriptor result in 128 matches.
AKAZE detector and ORB descriptor result in 127 matches.
AKAZE detector and ORB descriptor result in 114 matches.
AKAZE detector and ORB descriptor result in 131 matches.
AKAZE detector and ORB descriptor result in 132 matches.
AKAZE detector and ORB descriptor result in 136 matches.
AKAZE detector and ORB descriptor result in 138 matches.
AKAZE detector and ORB descriptor result in 144 matches.
23)
AKAZE detector and FREAK descriptor result in 123 matches.
AKAZE detector and FREAK descriptor result in 127 matches.
AKAZE detector and FREAK descriptor result in 129 matches.
AKAZE detector and FREAK descriptor result in 121 matches.
AKAZE detector and FREAK descriptor result in 123 matches.
AKAZE detector and FREAK descriptor result in 132 matches.
AKAZE detector and FREAK descriptor result in 145 matches.
AKAZE detector and FREAK descriptor result in 146 matches.
AKAZE detector and FREAK descriptor result in 135 matches.
24)
AKAZE detector and AKAZE descriptor result in 135 matches.
AKAZE detector and AKAZE descriptor result in 138 matches.
AKAZE detector and AKAZE descriptor result in 132 matches.
AKAZE detector and AKAZE descriptor result in 126 matches.
AKAZE detector and AKAZE descriptor result in 128 matches.
AKAZE detector and AKAZE descriptor result in 146 matches.
AKAZE detector and AKAZE descriptor result in 147 matches.
AKAZE detector and AKAZE descriptor result in 149 matches.
AKAZE detector and AKAZE descriptor result in 148 matches.
25)
AKAZE detector and SIFT descriptor result in 132 matches.
AKAZE detector and SIFT descriptor result in 134 matches.
AKAZE detector and SIFT descriptor result in 129 matches.
AKAZE detector and SIFT descriptor result in 136 matches.
AKAZE detector and SIFT descriptor result in 136 matches.
AKAZE detector and SIFT descriptor result in 147 matches.
AKAZE detector and SIFT descriptor result in 147 matches.
AKAZE detector and SIFT descriptor result in 153 matches.
AKAZE detector and SIFT descriptor result in 149 matches.
26)
SIFT detector and BRIEF descriptor result in 86 matches.
SIFT detector and BRIEF descriptor result in 76 matches.
SIFT detector and BRIEF descriptor result in 72 matches.
SIFT detector and BRIEF descriptor result in 83 matches.
SIFT detector and BRIEF descriptor result in 69 matches.
SIFT detector and BRIEF descriptor result in 75 matches.
SIFT detector and BRIEF descriptor result in 76 matches.
SIFT detector and BRIEF descriptor result in 69 matches.
SIFT detector and BRIEF descriptor result in 87 matches.
27)
SIFT detector and FREAK descriptor result in 63 matches.
SIFT detector and FREAK descriptor result in 70 matches.
SIFT detector and FREAK descriptor result in 63 matches.
SIFT detector and FREAK descriptor result in 65 matches.
SIFT detector and FREAK descriptor result in 63 matches.
SIFT detector and FREAK descriptor result in 59 matches.
SIFT detector and FREAK descriptor result in 64 matches.
SIFT detector and FREAK descriptor result in 65 matches.
SIFT detector and FREAK descriptor result in 79 matches.
28)
SIFT detector and SIFT descriptor result in 81 matches.
SIFT detector and SIFT descriptor result in 79 matches.
SIFT detector and SIFT descriptor result in 83 matches.
SIFT detector and SIFT descriptor result in 92 matches.
SIFT detector and SIFT descriptor result in 90 matches.
SIFT detector and SIFT descriptor result in 82 matches.
SIFT detector and SIFT descriptor result in 82 matches.
SIFT detector and SIFT descriptor result in 100 matches.
SIFT detector and SIFT descriptor result in 101 matches.

## MP9
according to time records below, top 3 combinations are
1. FAST detector and BRIEF descriptor
2. FAST detector and AKAZE descriptor
3. FAST detector and ORB descriptor

```````
SHITOMASI detector and BRIEF descriptor process 10 images take 191.703 ms
SHITOMASI detector and ORB descriptor process 10 images take 172.301 ms
SHITOMASI detector and FREAK descriptor process 10 images take 328.108 ms
SHITOMASI detector and AKAZE descriptor process 10 images take 113.833 ms
SHITOMASI detector and SIFT descriptor process 10 images take 233.707 ms
HARRIS detector and BRIEF descriptor process 10 images take 111.918 ms
HARRIS detector and ORB descriptor process 10 images take 115.55 ms
HARRIS detector and FREAK descriptor process 10 images take 294.099 ms
HARRIS detector and AKAZE descriptor process 10 images take 104.226 ms
HARRIS detector and SIFT descriptor process 10 images take 211.489 ms
FAST detector and BRIEF descriptor process 10 images take 69.0447 ms
FAST detector and ORB descriptor process 10 images take 72.7695 ms
FAST detector and FREAK descriptor process 10 images take 254.92 ms
FAST detector and AKAZE descriptor process 10 images take 70.4784 ms
FAST detector and SIFT descriptor process 10 images take 183.68 ms
BRISK detector and BRIEF descriptor process 10 images take 672.841 ms
BRISK detector and ORB descriptor process 10 images take 740.344 ms
BRISK detector and FREAK descriptor process 10 images take 861.023 ms
BRISK detector and AKAZE descriptor process 10 images take 679.506 ms
BRISK detector and SIFT descriptor process 10 images take 931.17 ms
ORB detector and BRIEF descriptor process 10 images take 388.927 ms
ORB detector and ORB descriptor process 10 images take 185.174 ms
ORB detector and FREAK descriptor process 10 images take 320.294 ms
ORB detector and AKAZE descriptor process 10 images take 142.712 ms
ORB detector and SIFT descriptor process 10 images take 344.337 ms
AKAZE detector and BRIEF descriptor process 10 images take 485.241 ms
AKAZE detector and ORB descriptor process 10 images take 482.353 ms
AKAZE detector and FREAK descriptor process 10 images take 648.013 ms
AKAZE detector and AKAZE descriptor process 10 images take 742.278 ms
AKAZE detector and SIFT descriptor process 10 images take 591.873 ms
SIFT detector and BRIEF descriptor process 10 images take 661.088 ms
SIFT detector and ORB descriptor process 10 images take 630.082 ms
SIFT detector and FREAK descriptor process 10 images take 824.392 ms
SIFT detector and AKAZE descriptor process 10 images take 622.509 ms
SIFT detector and SIFT descriptor process 10 images take 1119 ms``````
