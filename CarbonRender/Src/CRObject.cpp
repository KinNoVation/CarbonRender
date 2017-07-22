#include "..\Inc\CRObject.h"

Object::Object(){}

void Object::SetPosition(float3 p)
{
	transform[0] = p.x;
	transform[1] = p.y;
	transform[2] = p.z;
}

void Object::SetScale(float3 s)
{
	transform[3] = s.x;
	transform[4] = s.y;
	transform[5] = s.z;
}

void Object::SetRotation(float3 r)
{
	transform[6] = r.x;
	transform[7] = r.y;
	transform[8] = r.z;
}

void Object::UpdateModelMatrix()
{
	modelMatrix = Scale(transform[3], transform[4], transform[5]) * 
				  Rotate(float3(1.0f, 0.0f, 0.0f), transform[6]).Normailze().ToMatrix() *
				  Rotate(float3(0.0f, 1.0f, 0.0f), transform[7]).Normailze().ToMatrix() *
				  Rotate(float3(0.0f, 0.0f, 1.0f), transform[8]).Normailze().ToMatrix() *
				  Translate(transform[0], transform[1], transform[2]);
}

float3 Object::GetPosition()
{
	float3 result;
	result.x = transform[0];
	result.y = transform[1];
	result.z = transform[2];

	return result;
}

float3 Object::GetScale()
{
	float3 result;
	result.x = transform[3];
	result.y = transform[4];
	result.z = transform[5];

	return result;
}

float3 Object::GetRotation()
{
	float3 result;
	result.x = transform[6];
	result.y = transform[7];
	result.z = transform[8];

	return result;
}

Matrix4x4 Object::GetModelMatrix()
{
	return modelMatrix;
}