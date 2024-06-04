#pragma once

#include <array>

#include "V3dTypes.h"

// canvasWidth,1,UINT        // Canvas width
// canvasHeight,2,UINT       // Canvas heighot
// absolute,3,BOOL           // true: absolute size; false: scale to canvas
// minBound,4,TRIPLE         // Scene minimum bounding box corners
// maxBound,5,TRIPLE         // Scene maximum bounding box corners
// orthographic,6,BOOL       // true: orthographic; false: perspective
// angleOfView,7,REAL        // Field of view angle (in radians)
// initialZoom,8,REAL        // Initial zoom
// viewportShift,9,PAIR      // Viewport shift (for perspective projection)
// viewportMargin,10,PAIR    // Margin around viewport
// light,11,TRIPLE,RGB       // Direction and color of each point light source
// background,12,RGBA        // Background color
// zoomFactor,13,REAL        // Zoom base factor
// zoomPinchFactor,14,REAL   // Zoom pinch factor
// zoomPinchCap,15,REAL      // Zoom pinch limit
// zoomStep,16,REAL          // Zoom power step
// shiftHoldDistance,17,REAL // Shift-mode maximum hold distance (pixels)
// shiftWaitTime,18,REAL     // Shift-mode hold time (milliseconds)
// vibrateTime,19,REAL       // Shift-mode vibrate time (milliseconds)

extern const std::array<size_t, 20> g_HeaderEntries;