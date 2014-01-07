//
//  GLSLPerspectiveDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 30.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLPerspectiveDrawing.h"
#include "GLResourceManager.h"
#include "GLSLAttribute.h"
#include "GLSLUniform.h"
#include "GLLogger.h"
#include "GLSLVertex.h"
#include "GLSLMatrix.h"



static const GLsizei PositionSize = 3;
static const GLsizei ColorSize = 4;



namespace GLRenderer
{
    void GLSLPerspectiveDrawing::SetProjectionMatrix(GLSLMatrix4 &rProjectionMatrix) const
    {
        GLSLUniform *projectionUniform = GetUniformByName("u_projection");
        projectionUniform->SetMatrix4f(rProjectionMatrix);
    }
    
    GLSLMatrix4 GLSLPerspectiveDrawing::GetProjectionMatrix() const
    {
        GLSLUniform *projectionUniform = GetUniformByName("u_projection");
        GLSLMatrix4 projectionMatrix = projectionUniform->GetMatrix4f();
        return projectionMatrix;
    }
    
    void GLSLPerspectiveDrawing::SetModelviewMatrix(GLSLMatrix4 &rModelviewMatrix) const
    {
        GLSLUniform *modelviewUniform = GetUniformByName("u_modelview");
        modelviewUniform->SetMatrix4f(rModelviewMatrix);
    }
    
    GLSLMatrix4 GLSLPerspectiveDrawing::GetModelviewMatrix() const
    {
        GLSLUniform *modelviewUniform = GetUniformByName("u_modelview");
        GLSLMatrix4 modelviewMatrix = modelviewUniform->GetMatrix4f();
        return modelviewMatrix;
    }
    
#pragma mark - Private Methods
    
    string GLSLPerspectiveDrawing::VertexShaderSource() const
    {
        string vertexShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PerspectiveShader.vsh");
        return vertexShaderSource;
    }
    
    string GLSLPerspectiveDrawing::FragmentShaderSource() const
    {
        string fragmentShaderSource = GLResourceManager::SharedInstance().LoadTextFileNamed("PerspectiveShader.fsh");
        return fragmentShaderSource;
    }
    
    void GLSLPerspectiveDrawing::InitializeAttributesWithCurrentBuffer() const
    {
        GLSLAttribute *positionAttribute = GetAttributeByName("a_position");
        GLSLAttribute *colorAttribute = GetAttributeByName("a_color");
        
        positionAttribute->SetBufferPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), 0);
        colorAttribute->SetBufferPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, sizeof(GLSLVertex1P1C), PositionSize);
    }
    
    void GLSLPerspectiveDrawing::InitializeAttributesWithVertexArray(GLSLVertexArray *pVertexArray) const
    {
        GLSLAttribute *positionAttribute = GetAttributeByName("a_position");
        GLSLAttribute *colorAttribute = GetAttributeByName("a_color");
        
        GLvoid *pPosition = pVertexArray->GetData();
        GLvoid *pColor = (GLfloat *)pPosition + PositionSize;
        
        GLsizei vertexSize = pVertexArray->GetVertexSize();
        
        positionAttribute->SetDataPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, vertexSize, pPosition);
        colorAttribute->SetDataPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, vertexSize, pColor);
    }
    
    void GLSLPerspectiveDrawing::InitializeAttributesWithVertexArrays(vector<GLSLVertexArray *> *pVertexArrays) const
    {
        GLSLAttribute *positionAttribute = GetAttributeByName("a_position");
        GLSLAttribute *colorAttribute = GetAttributeByName("a_color");
        
        GLSLVertexArray *pPositionArray = pVertexArrays->at(0);
        GLSLVertexArray *pColorArray = pVertexArrays->at(1);
        
        GLvoid *pPosition = pPositionArray->GetData();
        GLvoid *pColor = pColorArray->GetData();
        
        positionAttribute->SetDataPointer(PositionSize, GLSL_DATA_TYPE_FLOAT, false, 0, pPosition);
        colorAttribute->SetDataPointer(ColorSize, GLSL_DATA_TYPE_FLOAT, false, 0, pColor);
    }
    
    void GLSLPerspectiveDrawing::InitializeUniforms() const
    {
        GLSLMatrix4 projectionMatrix = GLSLMatrix4::Frustum(-2.0f, 2.0f, -2.0f, 2.0f, 4.0f, 10.0f);
        SetProjectionMatrix(projectionMatrix);
        
        GLSLMatrix4 modelviewMatrix;
        SetModelviewMatrix(modelviewMatrix);
    }
}