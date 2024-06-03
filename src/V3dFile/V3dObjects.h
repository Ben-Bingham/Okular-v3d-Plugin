#pragma once

#include <string>
#include <vector>
#include <memory>
#include <array>

#include "V3dObject.h"

enum ObjectTypes {
    MATERIAL = 1,
    TRANSFORM = 2,
    ELEMENT = 3,
    CENTERS = 4,
    HEADER = 5,

    LINE = 64,
    TRIANGLE = 65,
    QUAD = 66,

    CURVE = 128,
    BEZIER_TRIANGLE = 129,
    BEZIER_PATCH = 130,

    LINE_COLOR = 192,
    TRIANGLE_COLOR = 193,
    QUAD_COLOR = 194,

    CURVE_COLOR = 256,
    BEZIER_TRIANGLE_COLOR = 257,
    BEZIER_PATCH_COLOR = 258,

    TRIANGLES = 512,

    DISK = 1024,
    CYLINDER = 1025,
    TUBE = 1026,
    SPHERE = 1027,
    HALF_SPHERE = 1028,

    ANIMATION = 2048,

    //#open2DPolygon=3136
    //#closed2DPolygon=3137
    //#open2DCurve=3200
    //#closed2DCurve=3201

    PIXEL = 4096,
};

class V3dHeader : public V3dObject {
public:
    V3dHeader();
    ~V3dHeader() override = default;

    std::vector<float> getVertices() override;

    UINT dataLength;
    std::vector<WORD> data;
};

class V3dCenter : public V3dObject {
public:
    V3dCenter();
    ~V3dCenter() override = default;

    std::vector<float> getVertices() override;

    UINT centersLength;
    std::vector<TRIPLE> centers;
};

class V3dMaterial : public V3dObject {
public:
    V3dMaterial();
    ~V3dMaterial() override = default;

    std::vector<float> getVertices() override;

    RGBA diffuse;
    RGBA emissive;
    RGBA specular;
    FLOAT shininess;
    FLOAT metallic;
    FLOAT fresnel0;
};

class V3dBezierPatch : public V3dObject {
public:
    V3dBezierPatch();
    ~V3dBezierPatch() override = default;

    std::vector<float> getVertices() override;

    std::array<TRIPLE, 16> controlPoints;
    UINT centerIndex;
    UINT materialIndex;
};

class V3dBezierTriangle : public V3dObject {
public:
    V3dBezierTriangle();
    ~V3dBezierTriangle() override = default;

    std::vector<float> getVertices() override;

    std::array<TRIPLE, 10> controlPoints;
    UINT centerIndex;
    UINT materialIndex;
};

class V3dBezierPatchWithCornerColors : public V3dObject {
public:
    V3dBezierPatchWithCornerColors();
    ~V3dBezierPatchWithCornerColors() override = default;

    std::vector<float> getVertices() override;

    std::array<TRIPLE, 16> controlPoints;
    UINT centerIndex;
    UINT materialIndex;
    std::array<RGBA, 4> cornerColors;
};

class V3dBezierTriangleWithCornerColors : public V3dObject {
public:
    V3dBezierTriangleWithCornerColors();
    ~V3dBezierTriangleWithCornerColors() override = default;

    std::vector<float> getVertices() override;

    std::array<TRIPLE, 10> controlPoints;
    UINT centerIndex;
    UINT materialIndex;
    std::array<RGBA, 3> cornerColors;
};

class V3dStraightPlanarQuad : public V3dObject {
public:
    V3dStraightPlanarQuad();
    ~V3dStraightPlanarQuad() override = default;

    std::vector<float> getVertices() override;

    std::array<TRIPLE, 4> vertices;
    UINT centerIndex;
    UINT materialIndex;
};

class V3dStraightTriangle : public V3dObject {
public:
    V3dStraightTriangle();
    ~V3dStraightTriangle() override = default;

    std::vector<float> getVertices() override;

    std::array<TRIPLE, 3> vertices;
    UINT centerIndex;
    UINT materialIndex;
};

class V3dStraightPlanarQuadWithCornderColors : public V3dObject {
public:
    V3dStraightPlanarQuadWithCornderColors();
    ~V3dStraightPlanarQuadWithCornderColors() override = default;

    std::vector<float> getVertices() override;

    std::array<TRIPLE, 4> vertices;
    UINT centerIndex;
    UINT materialIndex;
    std::array<RGBA, 4> cornerColors;
};

class V3dStraightTriangleWithCornderColors : public V3dObject {
public:
    V3dStraightTriangleWithCornderColors();
    ~V3dStraightTriangleWithCornderColors() override = default;

    std::vector<float> getVertices() override;

    std::array<TRIPLE, 3> vertices;
    UINT centerIndex;
    UINT materialIndex;
    std::array<RGBA, 3> cornerColors;
};

class V3dTriangleGroup : public V3dObject {
public:
    V3dTriangleGroup();
    ~V3dTriangleGroup() override = default;

    std::vector<float> getVertices() override;

    struct Index {
        std::array<UINT, 3> vertexPositionIndices;
        std::array<UINT, 3> vertexNormalIndices;
        std::array<UINT, 3> vertexColorIndices;
    };

    UINT nI;
    UINT nP;
    std::vector<TRIPLE> vertexPositions; // size is nP
    UINT nN;
    std::vector<TRIPLE> vertexNormalArray; // size is nN
    BOOL explicitNI;
    UINT nC;
    std::vector<RGBA> vertexColorArray; // size is nC
    BOOL explicitCI;
    std::vector<Index> indices; // size is nI;
    UINT centerIndex;
    UINT materialIndex;
};

class V3dSphere : public V3dObject {
public:
    V3dSphere();
    ~V3dSphere() override = default;

    std::vector<float> getVertices() override;

    TRIPLE center;
    REAL radius;
    UINT centerIndex;
    UINT materialIndex;
};

class V3dHemiSphere : public V3dObject {
public:
    V3dHemiSphere();
    ~V3dHemiSphere() override = default;

    std::vector<float> getVertices() override;

    TRIPLE center;
    REAL radius;
    UINT centerIndex;
    UINT materialIndex;
    REAL polarAngle;
    REAL azimuthalAngle;
};

class V3dDisk : public V3dObject {
public:
    V3dDisk();
    ~V3dDisk() override = default;

    std::vector<float> getVertices() override;

    TRIPLE center;
    REAL radius;
    UINT centerIndex;
    UINT materialIndex;
    REAL polarAngle;
    REAL azimuthalAngle;
};

class V3dCylinder : public V3dObject {
public:
    V3dCylinder();
    ~V3dCylinder() override = default;

    std::vector<float> getVertices() override;

    TRIPLE center;
    REAL radius;
    REAL height;
    UINT centerIndex;
    UINT materialIndex;
    REAL polarAngle;
    REAL azimuthalAngle;
};

class V3dTube : public V3dObject {
public:
    V3dTube();
    ~V3dTube() override = default;

    std::vector<float> getVertices() override;

    std::array<TRIPLE, 4> controlPoints;
    REAL width;
    UINT centerIndex;
    UINT materialIndex;
    BOOL core;
};

class V3dBezierCurve : public V3dObject {
public:
    V3dBezierCurve();
    ~V3dBezierCurve() override = default;

    std::vector<float> getVertices() override;

    std::array<TRIPLE, 4> controlPoints;
    UINT centerIndex;
    UINT materialIndex;
};

class V3dLineSegment : public V3dObject {
public:
    V3dLineSegment();
    ~V3dLineSegment() override = default;

    std::vector<float> getVertices() override;

    std::array<TRIPLE, 2> endpoints;
    UINT centerIndex;
    UINT materialIndex;
};

class V3dPixel : public V3dObject {
public:
    V3dPixel();
    ~V3dPixel() override = default;

    std::vector<float> getVertices() override;

    TRIPLE position;
    UINT centerIndex;
    UINT materialIndex;
};