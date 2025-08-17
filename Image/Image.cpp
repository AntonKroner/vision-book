module;
#include <cstdint>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
export module Image;
export class Image {
  public:
    struct {
        int x;
        int y;
    } size = { .x = 0, .y = 0 };
    int comp = 0;
    uint8_t* bytes = nullptr;
    float* intensity = nullptr;
    Image(const char* const file) {
      if (!(this->bytes = stbi_load(file, &this->size.x, &this->size.y, &this->comp, 0))) {
        throw "Unable to load image.";
      }
    }

    float intensityGet(int x, int y) {
      if (!this->intensity) {
        this->intensity = new float[x * y];
        for (int i = 0; x * y > i; i++) {
          this->intensity[i] = this->bytes[i * 4 + 0] + this->bytes[i * 4 + 1]
                               + this->bytes[i * 4 + 2] + this->bytes[i * 4 + 3];
        }
      }
      return this->intensity[x + this->size.x * y];
    }
};
