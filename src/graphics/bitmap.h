//
// Created by User on 8/6/2022.
//

#ifndef W3D_BITMAP_H
#define W3D_BITMAP_H


#include "glad/gl.h"
#include <vector>
class DG_Bitmap {
    float mvertdata[32]{
            0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
            0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left

    };
    unsigned int mindices[6]{
        0, 1, 3,
        1, 2, 3
    };
    std::vector<unsigned char> mdata{};
    unsigned char* mpdata{nullptr};
    unsigned int mvao;
    unsigned int mvbo;
    unsigned int mebo;
    unsigned int mtexture;
    unsigned int mwidth;
    unsigned int mheight;
    unsigned int mnrchannels;
public:
    explicit DG_Bitmap(unsigned int height, unsigned int width, int nrChannels) :
    mwidth(width),
    mheight(height),
    mnrchannels(nrChannels)
    {
        unsigned int vbo;

        glGenVertexArrays(1, &mvao);
        glGenBuffers(1, &mvbo);
        glGenBuffers(1, &mvbo);

        glBindVertexArray(mvao);

        glBindBuffer(GL_ARRAY_BUFFER, mvbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(mvertdata), mvertdata, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mindices), mindices, GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        // texture coord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        // load and create a texture
        // -------------------------
        // texture 0
        // ---------
        glGenTextures(1, &mtexture);
        glBindTexture(GL_TEXTURE_2D, mtexture);
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        mdata.resize(mnrchannels * mwidth * mheight);
        mpdata = mdata.data();

    }
    ~DG_Bitmap()
    {

    }
};


#endif //W3D_BITMAP_H
