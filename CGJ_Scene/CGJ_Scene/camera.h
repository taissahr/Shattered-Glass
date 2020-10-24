﻿#ifndef CAMERA_H
#define CAMERA_H

#include "matrix.h"
#include "quaternions.h"

struct Projection {
	virtual mat4 getProjectionMatrix() = 0;
};

struct OrthoProjection : Projection {
	float left, right, bottom, top, near, far;
	OrthoProjection(float l, float r, float b, float t, float n, float f);
	mat4 getProjectionMatrix();
};

struct PerspectiveProjection : Projection {
	float fovy, aspect, nearZ, farZ;
	PerspectiveProjection(float fovy, float aspect, float nearZ, float farZ);
	mat4 getProjectionMatrix();
};

struct Camera {
	quaternion rotation;
	float distance;
	Projection *projection;
	Camera();
	Camera(float distance, quaternion rot, Projection *p);
	mat4 getProjectionMatrix();
	mat4 getViewMatrix();
	void translate(vec3 v);
};

#endif // !CAMERA_H