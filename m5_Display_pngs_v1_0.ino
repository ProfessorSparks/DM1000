#include <M5Unified.h>
#include <SD.h>

// Matthew Sparks
// ProfessorSparks@gmail.com
// May 8 2025 
// This program is a first excercise for me to learn how to display and overlay transparent .pngs on the M5cardputer
// this is basically just a slideshow at this point

// Ver 1.0

// 
// Notes on PNG format
// Color Mode  RGB or RGBA (8-bit per channel)- 24/16 Million
// Transparency  Yes (use alpha channel, not indexed color)
// Interlacing ❌ Non-interlaced
// Bit Depth 8 bits per channel
// No compression
// Resolution (DPI/PPI)  72 PPI
// Dimensions  240x136
// Transparency Format Alpha channel, not transparent background flag
//

void showPng(const char* path, int x = 0, int y = 0) {
  File file = SD.open(path);
  if (!file) {
    Serial.printf("Failed to open %s\n", path);
    return;
  }

  size_t len = file.size();
  uint8_t* buf = (uint8_t*)malloc(len);
  if (!buf) {
    Serial.println("Failed to allocate memory");
    file.close();
    return;
  }

  file.read(buf, len);
  file.close();

  M5.Display.startWrite();  // <--- NEW
  if (!M5.Display.drawPng(buf, len, x, y)) {
    Serial.printf("Failed to draw PNG: %s\n", path);
  }
  M5.Display.endWrite();    // <--- NEW

  free(buf);
}


void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);

  Serial.begin(115200);
  if (!SD.begin()) {
    Serial.println("SD mount failed!");
    while (true) { delay(100); }
  }
  Serial.println("SD mounted.");

  M5.Display.setBrightness(128);
  M5.Display.clear();
}

void loop() {
  M5.update();
M5.Display.setColorDepth(32);
  M5.Display.clear();
  showPng("/0.png", 0, 0);
  showPng("/North.png", 0, 0);
  delay(3000);

M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/20100.png", 0, 0);
  showPng("/East.png", 0, 0);
  showPng("/Keyhole2.png", 0, 0);
  delay(3000);

  M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/0.png", 0, 0);
  showPng("/North.png", 0, 0);
  delay(3000);

  M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/101.png", 0, 0);
  showPng("/West.png", 0, 0);
  delay(3000);

  M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/0.png", 0, 0);
  showPng("/West.png", 0, 0);
  delay(3000);

    M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/410011000.png", 0, 0);
  showPng("/North.png", 0, 0);
  delay(3000);

    M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/3001100.png", 0, 0);
  showPng("/North.png", 0, 0);
  delay(3000);

  M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/111.png", 0, 0);
  showPng("/West.png", 0, 0);
  delay(3000);

  M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/0.png", 0, 0);
  showPng("/West.png", 0, 0);
  delay(3000);

  M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/100.png", 0, 0);
  showPng("/South.png", 0, 0);
    showPng("/Box1.png", 0, 0);
  delay(3000);
  
M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/111.png", 0, 0);
  showPng("/East.png", 0, 0);
   delay(3000);

    M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/100.png", 0, 0);
  showPng("/North.png", 0, 0);
        showPng("/Box1.png", 0, 0);
  delay(3000);

  M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/111.png", 0, 0);
  showPng("/East.png", 0, 0);
   delay(3000);
   
    M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/3001100.png", 0, 0);
  showPng("/North.png", 0, 0);
  delay(3000);

      M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/20110.png", 0, 0);
  showPng("/North.png", 0, 0);
  delay(3000);

        M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/111.png", 0, 0);
  showPng("/North.png", 0, 0);
  delay(3000);

        M5.Display.setColorDepth(32);
  //M5.Display.clear();
  showPng("/0.png", 0, 0);
  showPng("/North.png", 0, 0);
  delay(3000);
}
