input.onButtonPressed(Button.A, function () {
    input.calibrateCompass()
})
input.onButtonPressed(Button.B, function () {
    input.clearCalibrationCompass()
})
input.assumeCalibratedCompass()
basic.forever(function () {
    basic.showNumber(input.isCalibratedCompass())
})
