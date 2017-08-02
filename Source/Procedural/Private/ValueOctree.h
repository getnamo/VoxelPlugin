#pragma once
#include <cmath>
#include <vector>
#include "CoreMinimal.h"
#include "Engine.h"

DECLARE_LOG_CATEGORY_EXTERN(ValueOctreeLog, Log, All);

class ValueOctree
{
public:
	ValueOctree(FIntVector position, int depth);
	~ValueOctree();

	// Center of the octree
	const FIntVector Position;
	const int Depth;



	inline int GetWidth();

	void CreateTree();

	ValueOctree* GetLeaf(FIntVector globalPosition);

	bool IsLeaf();

	bool IsDirty();

	signed char GetValue(FIntVector globalPosition);
	FColor GetColor(FIntVector globalPosition);

	void SetValue(FIntVector globalPosition, signed char value);
	void SetColor(FIntVector globalPosition, FColor color);

	bool IsInChunk(FIntVector globalPosition);

	FIntVector LocalToGlobal(FIntVector localPosition);
	FIntVector GlobalToLocal(FIntVector globalPosition);

protected:
	/*
	bottom      top
	-----> y
	| 0 | 2    4 | 6
	v 1 | 3    5 | 7
	x

	*/
	ValueOctree* Childs[8];

	std::vector<signed char> Values;
	std::vector<FColor> Colors;

	bool bIsDirty;
	bool bIsLeaf;

	void CreateChilds();
};