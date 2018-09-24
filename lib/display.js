'use strict';

const display = require('bindings')('display.node');

const DISPLAY_ORIENTATION_DEFAULT = 0;
const DISPLAY_ORIENTATION_90 = 1;
const DISPLAY_ORIENTATION_180 = 2;
const DISPLAY_ORIENTATION_270 = 3;

module.exports = {
    rotate: display.rotate,
    flip: () => {
        const currentOrientation = display.rotate();
        switch (currentOrientation) {
            case DISPLAY_ORIENTATION_DEFAULT:
                return display.rotate(DISPLAY_ORIENTATION_180);
            case DISPLAY_ORIENTATION_180:
                return display.rotate(DISPLAY_ORIENTATION_DEFAULT);
        }
    }
};
