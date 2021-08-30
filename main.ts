input.onButtonPressed(Button.A, function () {
    input.calibrateCompass()
})
input.onButtonPressed(Button.B, function () {
    input.clearCalibrationCompass()
})
basic.forever(function () {
    basic.showNumber(input.isCalibratedCompass())
})
