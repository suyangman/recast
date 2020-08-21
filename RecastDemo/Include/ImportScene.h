#pragma once

#include <string>
#include "math/Public.h"
#include "vector"
#pragma pack(1)
struct ImportShape
{
    char szName[64];
	//1箱子 2球体 3胶囊 4网格边界
    unsigned char byType;
	uint32_t uClientUID;
    Vector3f vLocation;
    Quaternionf qRotate;
    Vector3f vScale;
    int iPenetrationCode;
    unsigned char byMaterialType;
    uint32_t uLayer;
    Vector3f vExtent;
};
#pragma pack()

struct ImportNode
{
    std::string name;
	uint32_t uClientUID;
    Vector3f    position; // zero (default)
    Quaternionf rotation; // identity (default)
    Vector3f    scale; // identity (default)
    int         iPenetrationCode;
    unsigned char        byMaterialType;
    int         meshIndex;// -1 default
    //Matrix4x4f  meshTransform;// identity (default)
    int			cameraIndex;
    int			layerIndex;

	 //array<ImportNode> children;   // unused

    // instantiatedLodMeshes.size() is:
    // 0 - when ImportNode doesn't have meshes
    // 1 - when ImportNode has a mesh which doesn't have to be split (then instantiatedLodMeshes[0].gameObject is the same as instantiatedGameObject)
    // N - when ImportNode has a mesh which has to be split (then instantiatedLodMeshes[i].gameObject is a child of instantiatedGameObject)
    //mutable array<InstantiatedMesh> instantiatedLodMeshes; // unused

    ImportNode() : cameraIndex(-1), layerIndex(-1)
    {
        position = Vector3f::zero;
        rotation = Quaternionf::identity();
        scale = Vector3f::one;
        meshIndex = -1;
        byMaterialType = 0;
    }
};

struct ImportMesh
{
    std::vector<Vector3f>        vertices;

    // Before mesh is split across seams, these arrays are per polygon vertex!
    // That is their size == polygons.size
	std::vector<Vector3f>      normals;
	std::vector<Vector4f>      tangents;
	std::vector<int>		   smoothingGroups;

    // Index buffer, potentially arbitrary number of indices per polygon
	std::vector<uint32_t>        polygons;

    // Per-polygon arrays.
	std::vector<uint32_t>        polygonSizes; // Size of each polygon
	std::vector<int>           materials; // Material index of each polygon

    std::string                name;
    bool	                            hasAnyQuads;
    bool	                            isConvex;


    ImportMesh() : hasAnyQuads(false), isConvex(false) {  }

    // src argument is optional
    void Reserve (int vertexCount, int faceCount, const ImportMesh* src);
    unsigned AdviseVertexFormat () const;
};

// reference: PxHeightFieldSample
struct ImportHeightFieldSample
{
    int16_t height;
	uint8_t isHole;
};

struct ImportHeightField
{
    int iInstanceID;

    // reference: PxHeightFieldDesc
    uint32_t nbRows;
    uint32_t nbColumns;
	std::vector<ImportHeightFieldSample> samples;
    float thickness;
    float convexEdgeThreshold;
    uint16_t flags;

    // reference: PxHeightFieldGeom
    float heightScale;
    float rowScale;
    float columnScale;
    uint8_t heightFieldFlags;

    // transform
    Vector3f position;
};

struct ImportScene {
	//形状
	std::vector<ImportShape> shapes;
	//节点
	std::vector<ImportNode> nodes;
	//网格
	std::vector<ImportMesh> meshes;
	//高度域
	std::vector<ImportHeightField> heightFields;
};
