//
//  Matrix.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "Matrix.h"

using namespace std;



namespace Renderer {
    
#pragma mark - Matrix2
    
    Matrix2::Matrix2() {
        x.x = 1.0f; x.y = 0.0f;
        y.x = 0.0f; y.y = 1.0f;
    }
    
    Matrix2 Matrix2::operator*(const Matrix2 &m) const {
        Matrix2 r;
        
        r.x.x = x.x * m.x.x + x.y * m.y.x;
        r.x.y = x.x * m.x.y + x.y * m.y.y;
        
        r.y.x = y.x * m.x.x + y.y * m.y.x;
        r.y.y = y.x * m.x.y + y.y * m.y.y;
        
        return r;
    }
    
    float Matrix2::Determinant() const {
        float determinant = x.x * y.y - x.y * y.x;
        return determinant;
    }
    
    bool Matrix2::Inverted(Matrix2 *pResultMatrix) const {
        float determinant = Determinant();
        if (determinant == 0.0f) {
            return false;
        }
        
        if (pResultMatrix) {
            float multiplier = 1.0f / determinant;
            pResultMatrix->x.x = multiplier * y.y;
            pResultMatrix->x.y = multiplier * -x.y;
            pResultMatrix->y.x = multiplier * -y.x;
            pResultMatrix->y.y = multiplier * x.x;
        }
        
        return true;
    }
    
    const float * Matrix2::Pointer() const {
        return &x.x;
    }
    
#pragma mark - Matrix3
    
    Matrix3::Matrix3() {
        x.x = 1.0f; x.y = 0.0f; x.z = 0.0f;
        y.x = 0.0f; y.y = 1.0f; y.z = 0.0f;
        z.x = 0.0f; z.y = 0.0f; z.z = 1.0f;
    }
    
    Matrix3 Matrix3::operator*(const Matrix3 &m) const {
        Matrix3 r;
        
        r.x.x = x.x * m.x.x + x.y * m.y.x + x.z * m.z.x;
        r.x.y = x.x * m.x.y + x.y * m.y.y + x.z * m.z.y;
        r.x.z = x.x * m.x.z + x.y * m.y.z + x.z * m.z.z;
        
        r.y.x = y.x * m.x.x + y.y * m.y.x + y.z * m.z.x;
        r.y.y = y.x * m.x.y + y.y * m.y.y + y.z * m.z.y;
        r.y.z = y.x * m.x.z + y.y * m.y.z + y.z * m.z.z;
        
        r.z.x = z.x * m.x.x + z.y * m.y.x + z.z * m.z.x;
        r.z.y = z.x * m.x.y + z.y * m.y.y + z.z * m.z.y;
        r.z.z = z.x * m.x.z + z.y * m.y.z + z.z * m.z.z;
        
        return r;
    }
    
    float Matrix3::Determinant() const {
        float determinant = x.x * (y.y * z.z - y.z * z.y) - x.y * (y.x * z.z - y.z * z.x) + x.z * (y.x * z.y - y.y * z.x);
        return determinant;
    }
    
    bool Matrix3::Inverted(Matrix3 *pResultMatrix) const {
        float determinant = Determinant();
        if (determinant == 0.0f) {
            return false;
        }
        
        if (pResultMatrix) {
            float multiplier = 1.0f / determinant;
            pResultMatrix->x.x = multiplier * (y.y * z.z - y.z * z.y);
            pResultMatrix->x.y = multiplier * (x.z * z.y - x.y * z.z);
            pResultMatrix->x.z = multiplier * (x.y * y.z - x.z * y.y);
            pResultMatrix->y.x = multiplier * (y.z * z.x - y.x * z.z);
            pResultMatrix->y.y = multiplier * (x.x * z.z - x.z * z.x);
            pResultMatrix->y.z = multiplier * (x.z * y.x - x.x * y.z);
            pResultMatrix->z.x = multiplier * (y.x * z.y - y.y * z.x);
            pResultMatrix->z.y = multiplier * (x.y * z.x - x.x * z.y);
            pResultMatrix->z.z = multiplier * (x.x * y.y - x.y * y.x);
        }
        
        return true;
    }
    
    Matrix3 Matrix3::Transposed() const {
        Matrix3 r;
        r.x.x = x.x; r.x.y = y.x; r.x.z = z.x;
        r.y.x = x.y; r.y.y = y.y; r.y.z = z.y;
        r.z.x = x.z; r.z.y = y.z; r.z.z = z.z;
        return r;
    }
    
    const float * Matrix3::Pointer() const {
        return &x.x;
    }
    
#pragma mark - Matrix4
    
    Matrix4::Matrix4() {
        x.x = 1.0f; x.y = 0.0f; x.z = 0.0f; x.w = 0.0f;
        y.x = 0.0f; y.y = 1.0f; y.z = 0.0f; y.w = 0.0f;
        z.x = 0.0f; z.y = 0.0f; z.z = 1.0f; z.w = 0.0f;
        w.x = 0.0f; w.y = 0.0f; w.z = 0.0f; w.w = 1.0f;
    }
    
    Matrix4::Matrix4(const Matrix3 &rMatrix) {
        x.x = rMatrix.x.x; x.y = rMatrix.x.y; x.z = rMatrix.x.z; x.w = 0.0f;
        y.x = rMatrix.y.x; y.y = rMatrix.y.y; y.z = rMatrix.y.z; y.w = 0.0f;
        z.x = rMatrix.z.x; z.y = rMatrix.z.y; z.z = rMatrix.z.z; z.w = 0.0f;
        w.x = 0.0f;        w.y = 0.0f;        w.z = 0.0f;        w.w = 1.0f;
    }
    
    Matrix4 Matrix4::operator*(const Matrix4 &m) const {
        Matrix4 r;
        
        r.x.x = x.x * m.x.x + x.y * m.y.x + x.z * m.z.x + x.w * m.w.x;
        r.x.y = x.x * m.x.y + x.y * m.y.y + x.z * m.z.y + x.w * m.w.y;
        r.x.z = x.x * m.x.z + x.y * m.y.z + x.z * m.z.z + x.w * m.w.z;
        r.x.w = x.x * m.x.w + x.y * m.y.w + x.z * m.z.w + x.w * m.w.w;
        
        r.y.x = y.x * m.x.x + y.y * m.y.x + y.z * m.z.x + y.w * m.w.x;
        r.y.y = y.x * m.x.y + y.y * m.y.y + y.z * m.z.y + y.w * m.w.y;
        r.y.z = y.x * m.x.z + y.y * m.y.z + y.z * m.z.z + y.w * m.w.z;
        r.y.w = y.x * m.x.w + y.y * m.y.w + y.z * m.z.w + y.w * m.w.w;
        
        r.z.x = z.x * m.x.x + z.y * m.y.x + z.z * m.z.x + z.w * m.w.x;
        r.z.y = z.x * m.x.y + z.y * m.y.y + z.z * m.z.y + z.w * m.w.y;
        r.z.z = z.x * m.x.z + z.y * m.y.z + z.z * m.z.z + z.w * m.w.z;
        r.z.w = z.x * m.x.w + z.y * m.y.w + z.z * m.z.w + z.w * m.w.w;
        
        r.w.x = w.x * m.x.x + w.y * m.y.x + w.z * m.z.x + w.w * m.w.x;
        r.w.y = w.x * m.x.y + w.y * m.y.y + w.z * m.z.y + w.w * m.w.y;
        r.w.z = w.x * m.x.z + w.y * m.y.z + w.z * m.z.z + w.w * m.w.z;
        r.w.w = w.x * m.x.w + w.y * m.y.w + w.z * m.z.w + w.w * m.w.w;
        
        return r;
    }
    
    Matrix4 & Matrix4::MakeTranslation(float tX, float tY, float tZ) {
        w.x = tX;
        w.y = tY;
        w.z = tZ;
        
        return *this;
    }
    
    Matrix4 & Matrix4::MakeScale(float xScale, float yScale, float zScale) {
        x.x = xScale;
        y.y = yScale;
        z.z = zScale;
        
        return *this;
    }
    
    Matrix4 & Matrix4::MakeScale(float scale) {
        x.x = scale;
        y.y = scale;
        z.z = scale;
        
        return *this;
    }
    
    Matrix4 & Matrix4::Translate(float tX, float tY, float tZ) {
        w.x += tX;
        w.y += tY;
        w.z += tZ;
        
        return *this;
    }
    
    Matrix4 & Matrix4::Scale(float xScale, float yScale, float zScale) {
        x.x *= xScale;
        y.y *= yScale;
        z.z *= zScale;
        
        return *this;
    }
    
    Matrix4 & Matrix4::Scale(float scale) {
        x.x *= scale;
        y.y *= scale;
        z.z *= scale;
        
        return *this;
    }
    
    Matrix4 & Matrix4::RotateX(float radians) {
        Matrix4 rotationMatrix = Matrix4::RotationX(radians);
        Matrix4 currentMatrix = *this;
        *this = rotationMatrix * currentMatrix;
        
        return *this;
    }
    
    Matrix4 & Matrix4::RotateY(float radians) {
        Matrix4 rotationMatrix = Matrix4::RotationY(radians);
        Matrix4 currentMatrix = *this;
        *this = rotationMatrix * currentMatrix;
        
        return *this;
    }
    
    Matrix4 & Matrix4::RotateZ(float radians) {
        Matrix4 rotationMatrix = Matrix4::RotationZ(radians);
        Matrix4 currentMatrix = *this;
        *this = rotationMatrix * currentMatrix;
        
        return *this;
    }
    
    Matrix4 & Matrix4::Transpose() {
        *this = this->Transposed();
        return *this;
    }
    
    Matrix4 Matrix4::Transposed() const {
        Matrix4 r;
        r.x.x = x.x; r.x.y = y.x; r.x.z = z.x; r.x.w = w.x;
        r.y.x = x.y; r.y.y = y.y; r.y.z = z.y; r.y.w = w.y;
        r.z.x = x.z; r.z.y = y.z; r.z.z = z.z; r.z.w = w.z;
        r.w.x = x.w; r.w.y = y.w; r.w.z = z.w; r.w.w = w.w;
        return r;
    }
    
    float Matrix4::Determinant() const {
        float a = x.x * (y.y * (z.z * w.w - z.w * w.z) - y.z * (z.y * w.w - z.w * w.y) + y.w * (z.y * w.z - z.z * w.y));
        float b = x.y * (y.x * (z.z * w.w - z.w * w.z) - y.z * (z.x * w.w - z.w * w.x) + y.w * (z.x * w.z - z.z * w.x));
        float c = x.z * (y.x * (z.y * w.w - z.w * w.y) - y.y * (z.x * w.w - z.w * w.x) + y.w * (z.x * w.y - z.y * w.x));
        float d = x.w * (y.x * (z.y * w.z - z.z * w.y) - y.y * (z.x * w.z - z.z * w.x) + y.z * (z.x * w.y - z.y * w.x));
        float determinant = a - b + c - d;
        
        return determinant;
    }
    
    bool Matrix4::Inverted(Matrix4 *pResultMatrix) const {
        float determinant = Determinant();
        if (determinant == 0.0f) {
            return false;
        }
        
        if (pResultMatrix) {
            float multiplier = 1.0f / determinant;
            
            pResultMatrix->x.x = multiplier * (y.y * z.z * w.w + y.z * z.w * w.y + y.w * z.y * w.z - y.y * z.w * w.z - y.z * z.y * w.w - y.w * z.z * w.y);
            pResultMatrix->x.y = multiplier * (x.y * z.w * w.z + x.z * z.y * w.w + x.w * z.z * w.y - x.y * z.z * w.w - x.z * z.w * w.y - x.w * z.y * w.z);
            pResultMatrix->x.z = multiplier * (x.y * y.z * w.w + x.z * y.w * w.y + x.w * y.y * w.z - x.y * y.w * w.z - x.z * y.y * w.w - x.w * y.z * w.y);
            pResultMatrix->x.w = multiplier * (x.y * y.w * z.z + x.z * y.y * z.w + x.w * y.z * z.y - x.y * y.z * z.w - x.z * y.w * z.y - x.w * y.y * z.z);
            
            pResultMatrix->y.x = multiplier * (y.x * z.w * w.z + y.z * z.x * w.w + y.w * z.z * w.x - y.x * z.z * w.w - y.z * z.w * w.x - y.w * z.x * w.z);
            pResultMatrix->y.y = multiplier * (x.x * z.z * w.w + x.z * z.w * w.x + x.w * z.x * w.z - x.x * z.w * w.z - x.z * z.x * w.w - x.w * z.z * w.x);
            pResultMatrix->y.z = multiplier * (x.x * y.w * w.z + x.z * y.x * w.w + x.w * y.z * w.x - x.x * y.z * w.w - x.z * y.w * w.x - x.w * y.x * w.z);
            pResultMatrix->y.w = multiplier * (x.x * y.z * z.w + x.z * y.w * z.x + x.w * y.x * z.z - x.x * y.w * z.z - x.z * y.x * z.w - x.w * y.z * z.x);
            
            pResultMatrix->z.x = multiplier * (y.x * z.y * w.w + y.y * z.w * w.x + y.w * z.x * w.y - y.x * z.w * w.y - y.y * z.x * w.w - y.w * z.y * w.x);
            pResultMatrix->z.y = multiplier * (x.x * z.w * w.y + x.y * z.x * w.w + x.w * z.y * w.x - x.x * z.y * w.w - x.y * z.w * w.x - x.w * z.x * w.y);
            pResultMatrix->z.z = multiplier * (x.x * y.y * w.w + x.y * y.w * w.x + x.w * y.x * w.y - x.x * y.w * w.y - x.y * y.x * w.w - x.w * y.y * w.x);
            pResultMatrix->z.w = multiplier * (x.x * y.w * z.y + x.y * y.x * z.w + x.w * y.y * z.x - x.x * y.y * z.w - x.y * y.w * z.x - x.w * y.x * z.y);
            
            pResultMatrix->w.x = multiplier * (y.x * z.z * w.y + y.y * z.x * w.z + y.z * z.y * w.x - y.x * z.y * w.z - y.y * z.z * w.x - y.z * z.x * w.y);
            pResultMatrix->w.y = multiplier * (x.x * z.y * w.z + x.y * z.z * w.x + x.z * z.x * w.y - x.x * z.z * w.y - x.y * z.x * w.z - x.z * z.y * w.x);
            pResultMatrix->w.z = multiplier * (x.x * y.z * w.y + x.y * y.x * w.z + x.z * y.y * w.x - x.x * y.y * w.z - x.y * y.z * w.x - x.z * y.x * w.y);
            pResultMatrix->w.w = multiplier * (x.x * y.y * z.z + x.y * y.z * z.x + x.z * y.x * z.y - x.x * y.z * z.y - x.y * y.x * z.z - x.z * y.y * z.x);
        }
        
        return true;
    }
    
    const float * Matrix4::Pointer() const {
        return &x.x;
    }
    
    Matrix4 Matrix4::Frustum(float left, float right, float bottom, float top, float near, float far) {
        float a = 2.0f * near / (right - left);
        float b = 2.0f * near / (top - bottom);
        float c = (right + left) / (right - left);
        float d = (top + bottom) / (top - bottom);
        float e = -(far + near) / (far - near);
        float f = -2.0f * far * near / (far - near);
        
        Matrix4 m;
        m.x.x = a;   m.x.y = 0.0; m.x.z = 0.0; m.x.w = 0.0;
        m.y.x = 0.0; m.y.y = b;   m.y.z = 0.0; m.y.w = 0.0;
        m.z.x = c;   m.z.y = d;   m.z.z = e;   m.z.w = -1.0;
        m.w.x = 0.0; m.w.y = 0.0; m.w.z = f;   m.w.w = 0.0;
        return m;
    }
    
    Matrix4 Matrix4::Frustum(float fovy, float aspect, float near, float far) {
        // TODO: Not tested. Doesn't work as expected
        // http://unspecified.wordpress.com/2012/06/21/calculating-the-gluperspective-matrix-and-other-opengl-matrix-maths/
        float f = 1.0f / tan(fovy / 2.0f);
        
        float a = f / aspect;
        float b = f;
        float c = (near + far) / (near - far);
        float d = 2.0f * near * far / (near - far);
        
        Matrix4 m;
        m.x.x = a;   m.x.y = 0.0; m.x.z = 0.0; m.x.w = 0.0;
        m.y.x = 0.0; m.y.y = b;   m.y.z = 0.0; m.y.w = 0.0;
        m.z.x = 0.0; m.z.y = 0.0; m.z.z = c;   m.z.w = -1.0;
        m.w.x = 0.0; m.w.y = 0.0; m.w.z = d;   m.w.w = 0.0;
        return m;
    }
    
    Matrix4 Matrix4::Ortho(float left, float right, float bottom, float top, float near, float far) {
        float a = 2.0f / (right - left);
        float b = -(right + left) / (right - left);
        float c = 2.0f / (top - bottom);
        float d = -(top + bottom) / (top - bottom);
        float e = -2.0f / (far - near);
        float f = -(far + near) / (far - near);
        
        Matrix4 m;
        m.x.x = a;   m.x.y = 0.0; m.x.z = 0.0; m.x.w = 0.0;
        m.y.x = 0.0; m.y.y = c;   m.y.z = 0.0; m.y.w = 0.0;
        m.z.x = 0.0; m.z.y = 0.0; m.z.z = e;   m.z.w = 0.0;
        m.w.x = b;   m.w.y = d;   m.w.z = f;   m.w.w = 1.0;
        return m;
    }
    
    Matrix4 Matrix4::Translation(float tX, float tY, float tZ) {
        Matrix4 m;
        m.x.x = 1.0f; m.x.y = 0.0f; m.x.z = 0.0f; m.x.w = 0.0f;
        m.y.x = 0.0f; m.y.y = 1.0f; m.y.z = 0.0f; m.y.w = 0.0f;
        m.z.x = 0.0f; m.z.y = 0.0f; m.z.z = 1.0f; m.z.w = 0.0f;
        m.w.x = tX;   m.w.y = tY;   m.w.z = tZ;   m.w.w = 1.0f;
        return m;
    }
    
    Matrix4 Matrix4::DoScale(float xScale, float yScale, float zScale) {
        Matrix4 m;
        m.x.x = xScale; m.x.y = 0.0f;   m.x.z = 0.0f;   m.x.w = 0.0f;
        m.y.x = 0.0f;   m.y.y = yScale; m.y.z = 0.0f;   m.y.w = 0.0f;
        m.z.x = 0.0f;   m.z.y = 0.0f;   m.z.z = zScale; m.z.w = 0.0f;
        m.w.x = 0.0f;   m.w.y = 0.0f;   m.w.z = 0.0f;   m.w.w = 1.0f;
        return m;
    }
    
    Matrix4 Matrix4::DoScale(float scale) {
        Matrix4 m;
        m.x.x = scale; m.x.y = 0.0f;  m.x.z = 0.0f;  m.x.w = 0.0f;
        m.y.x = 0.0f;  m.y.y = scale; m.y.z = 0.0f;  m.y.w = 0.0f;
        m.z.x = 0.0f;  m.z.y = 0.0f;  m.z.z = scale; m.z.w = 0.0f;
        m.w.x = 0.0f;  m.w.y = 0.0f;  m.w.z = 0.0f;  m.w.w = 1.0f;
        return m;
    }
    
    Matrix4 Matrix4::RotationX(float radians) {
        float s = sin(radians);
        float c = cos(radians);
        
        Matrix4 m;
        m.x.x = 1.0f; m.x.y = 0.0f; m.x.z = 0.0f; m.x.w = 0.0f;
        m.y.x = 0.0f; m.y.y = c;    m.y.z = s;    m.y.w = 0.0f;
        m.z.x = 0.0f; m.z.y = -s;   m.z.z = c;    m.z.w = 0.0f;
        m.w.x = 0.0f; m.w.y = 0.0f; m.w.z = 0.0f; m.w.w = 1.0f;
        return m;
    }
    
    Matrix4 Matrix4::RotationY(float radians) {
        float s = sin(radians);
        float c = cos(radians);
        
        Matrix4 m;
        m.x.x = c;    m.x.y = 0.0f; m.x.z = -s;   m.x.w = 0.0f;
        m.y.x = 0.0f; m.y.y = 1.0f; m.y.z = 0.0f; m.y.w = 0.0f;
        m.z.x = s;    m.z.y = 0.0f; m.z.z = c;    m.z.w = 0.0f;
        m.w.x = 0.0f; m.w.y = 0.0f; m.w.z = 0.0f; m.w.w = 1.0f;
        return m;
    }
    
    Matrix4 Matrix4::RotationZ(float radians) {
        float s = sin(radians);
        float c = cos(radians);
        
        Matrix4 m;
        m.x.x = c;    m.x.y = s;    m.x.z = 0.0f; m.x.w = 0.0f;
        m.y.x = -s;   m.y.y = c;    m.y.z = 0.0f; m.y.w = 0.0f;
        m.z.x = 0.0f; m.z.y = 0.0f; m.z.z = 1.0f; m.z.w = 0.0f;
        m.w.x = 0.0f; m.w.y = 0.0f; m.w.z = 0.0f; m.w.w = 1.0f;
        return m;
    }
}