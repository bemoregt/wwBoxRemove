# ofxBoxRemove
Bounding Box removal for Openframeworks using ofxCv.

![result example]( https://github.com/bemoregt/ofxBoxRemove/blob/master/BoxRemoveTest.png "Inpaint")
- Test Result
- Clockwise order : before, after, dilated mask, original mask.

### Algorithm
- Make Mask using InRange fuction of OpenCV
- Remove using InPaint function of OpenCV

### Dependency
- OpenFrameworks 0.10.1
- ofxCv
- ofxOpenCv
- ofxGUI
- XCode 10.12.x
- OSX Mojave

### Next Plan
- Add Hue, Saturation, Value Histogram
- Optimal Dilation of masks.

### Reference
- Original Source from: https://cafe.naver.com/opencv/52555
