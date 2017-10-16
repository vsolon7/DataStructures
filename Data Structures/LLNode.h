#pragma once

struct LLNode
{
	LLNode(float v, LLNode *next = nullptr)
	{
		val = v;
		nextNode = next;
	}

	float val;
	LLNode *nextNode;
};