#ifndef _SCREENSHOT_H_
#define _SCREENSHOT_H_
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <images/stb_image_write.h>

int saveScreenshot(const char *filename)
{
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    int x = viewport[0];
    int y = viewport[1];
    int width = viewport[2];
    int height = viewport[3];

	stbi_flip_vertically_on_write(true);
    char *data = (char*) malloc((size_t) (width * height * 3));
	
    if(!data) return 0;
    
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

    int saved = stbi_write_png(filename, width, height, 3, data, 0);

    free(data);

    return saved;
}

#endif
