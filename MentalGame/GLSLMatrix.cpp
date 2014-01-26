//
//  GLSLMatrix.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 25.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLMatrix.h"

using namespace std;



namespace Renderer {
    
#pragma mark - GLSLMatrix2
    
    const float * GLSLMatrix2::Pointer() const {
        return &x.x;
    }
    
#pragma mark - GLSLMatrix3
    
    const float * GLSLMatrix3::Pointer() const {
        return &x.x;
    }
    
#pragma mark - GLSLMatrix4
    
    GLSLMatrix4::GLSLMatrix4() {
        x.x = 1.0; x.y = 0.0; x.z = 0.0; x.w = 0.0;
        y.x = 0.0; y.y = 1.0; y.z = 0.0; y.w = 0.0;
        z.x = 0.0; z.y = 0.0; z.z = 1.0; z.w = 0.0;
        w.x = 0.0; w.y = 0.0; w.z = 0.0; w.w = 1.0;
    }
    
    GLSLMatrix4 GLSLMatrix4::operator * (const GLSLMatrix4 &m) const {
        GLSLMatrix4 r;
        
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
    
    GLSLMatrix4 & GLSLMatrix4::Translate(float tX, float tY, float tZ) {
        w.x += tX;
        w.y += tY;
        w.z += tZ;
        
        return *this;
    }
    
    GLSLMatrix4 & GLSLMatrix4::RotateX(float radians) {
        GLSLMatrix4 rotationMatrix = GLSLMatrix4::RotationX(radians);
        GLSLMatrix4 currentMatrix = *this;
        *this = rotationMatrix * currentMatrix;
        
        return *this;
    }
    
    GLSLMatrix4 & GLSLMatrix4::RotateY(float radians) {
        GLSLMatrix4 rotationMatrix = GLSLMatrix4::RotationY(radians);
        GLSLMatrix4 currentMatrix = *this;
        *this = rotationMatrix * currentMatrix;
        
        return *this;
    }
    
    GLSLMatrix4 & GLSLMatrix4::RotateZ(float radians) {
        GLSLMatrix4 rotationMatrix = GLSLMatrix4::RotationZ(radians);
        GLSLMatrix4 currentMatrix = *this;
        *this = rotationMatrix * currentMatrix;
        
        return *this;
    }
    
    const float * GLSLMatrix4::Pointer() const {
        return &x.x;
    }
    
    GLSLMatrix4 GLSLMatrix4::Frustum(float left, float right, float bottom, float top, float near, float far) {
        float a = 2 * near / (right - left);
        float b = 2 * near / (top - bottom);
        float c = (right + left) / (right - left);
        float d = (top + bottom) / (top - bottom);
        float e = -(far + near) / (far - near);
        float f = - 2 * far * near / (far - near);
        
        GLSLMatrix4 m;
        m.x.x = a;   m.x.y = 0.0; m.x.z = 0.0; m.x.w = 0.0;
        m.y.x = 0.0; m.y.y = b;   m.y.z = 0.0; m.y.w = 0.0;
        m.z.x = c;   m.z.y = d;   m.z.z = e;   m.z.w = -1.0;
        m.w.x = 0.0; m.w.y = 0.0; m.w.z = f;   m.w.w = 0.0;
        return m;
    }
    
    GLSLMatrix4 GLSLMatrix4::Translation(float tX, float tY, float tZ) {
        GLSLMatrix4 m;
        m.x.x = 1.0f; m.x.y = 0.0f; m.x.z = 0.0f; m.x.w = 0.0f;
        m.y.x = 0.0f; m.y.y = 1.0f; m.y.z = 0.0f; m.y.w = 0.0f;
        m.z.x = 0.0f; m.z.y = 0.0f; m.z.z = 1.0f; m.z.w = 0.0f;
        m.w.x = tX;   m.w.y = tY;   m.w.z = tZ;   m.w.w = 1.0f;
        return m;
    }
    
    GLSLMatrix4 GLSLMatrix4::RotationX(float radians) {
        float s = sin(radians);
        float c = cos(radians);
        
        GLSLMatrix4 m;
        m.x.x = 1.0f; m.x.y = 0.0f; m.x.z = 0.0f; m.x.w = 0.0f;
        m.y.x = 0.0f; m.y.y = c;    m.y.z = s;    m.y.w = 0.0f;
        m.z.x = 0.0f; m.z.y = -s;   m.z.z = c;    m.z.w = 0.0f;
        m.w.x = 0.0f; m.w.y = 0.0f; m.w.z = 0.0f; m.w.w = 1.0f;
        return m;
    }
    
    GLSLMatrix4 GLSLMatrix4::RotationY(float radians) {
        float s = sin(radians);
        float c = cos(radians);
        
        GLSLMatrix4 m;
        m.x.x = c;    m.x.y = 0.0f; m.x.z = -s;   m.x.w = 0.0f;
        m.y.x = 0.0f; m.y.y = 1.0f; m.y.z = 0.0f; m.y.w = 0.0f;
        m.z.x = s;    m.z.y = 0.0f; m.z.z = c;    m.z.w = 0.0f;
        m.w.x = 0.0f; m.w.y = 0.0f; m.w.z = 0.0f; m.w.w = 1.0f;
        return m;
    }
    
    GLSLMatrix4 GLSLMatrix4::RotationZ(float radians) {
        float s = sin(radians);
        float c = cos(radians);
        
        GLSLMatrix4 m;
        m.x.x = c;    m.x.y = s;    m.x.z = 0.0f; m.x.w = 0.0f;
        m.y.x = -s;   m.y.y = c;    m.y.z = 0.0f; m.y.w = 0.0f;
        m.z.x = 0.0f; m.z.y = 0.0f; m.z.z = 1.0f; m.z.w = 0.0f;
        m.w.x = 0.0f; m.w.y = 0.0f; m.w.z = 0.0f; m.w.w = 1.0f;
        return m;
    }
}