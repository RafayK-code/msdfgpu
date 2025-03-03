#pragma once

#include <vector>

namespace msdfgpu
{
    bool Initialize();
    bool Shutdown();

    struct Vector2;
    struct Color;
    class Shape;
    class Contour;

#ifdef MSDFGPU_FONT

    struct FreetypeHandle;
    struct FontHandle;

    FreetypeHandle* InitializeFreetype();
    bool ShutdownFreetype(FreetypeHandle* handle);

    FontHandle* CreateFont(FreetypeHandle* handle, const char* file);
    bool DestroyFont(FontHandle* handle);

#endif

    enum class EdgeColor {
        BLACK = 0,
        RED = 1,
        GREEN = 2,
        YELLOW = 3,
        BLUE = 4,
        MAGENTA = 5,
        CYAN = 6,
        WHITE = 7
    };

    class Edge
    {
    public:
        EdgeColor color;
    };

    class Contour
    {
        std::vector<Vector2> points;
        bool isClockwise = true;
    };

    class Shape
    {
    public:
        Shape() = default;

        void AddContour();
    };

#ifdef MSDFGPU_FONT

    bool CreateShapeFromGlyph(Shape& shape, FontHandle* handle, char32_t glyph);

#endif

    struct Vector2
    {
        float x, y;


    };
}