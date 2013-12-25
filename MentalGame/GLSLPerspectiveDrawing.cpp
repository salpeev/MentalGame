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



namespace GLRenderer
{
    void GLSLPerspectiveDrawing::SetModelviewMatrix(GLSLMatrix4 &rModelviewMatrix)
    {
        m_modelviewMatrix = rModelviewMatrix;
    }
    
    GLSLMatrix4 GLSLPerspectiveDrawing::GetModelviewMatrix() const
    {
        return m_modelviewMatrix;
    }
    
    void GLSLPerspectiveDrawing::SetProjectionMatrix(GLSLMatrix4 &rProjectionMatrix)
    {
        m_projectionMatrix = rProjectionMatrix;
    }
    
    GLSLMatrix4 GLSLPerspectiveDrawing::GetProjectionMatrix() const
    {
        return m_projectionMatrix;
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
    
    void GLSLPerspectiveDrawing::InitializeAttributes(const map<string, GLRenderer::GLSLAttribute *> *pAttributes, GLvoid *pData) const
    {
        GLSLAttribute *positionAttribute = pAttributes->at("a_position");
        GLSLAttribute *colorAttribute = pAttributes->at("a_color");
        
        positionAttribute->EnableArray();
        colorAttribute->EnableArray();
        
        GLint positionSize = 3;
        GLint colorSize = 4;
        
        GLvoid *pPosition = NULL;
        GLvoid *pColor = NULL;
        
        if (pData)
        {
            pPosition = pData;
            pColor = (GLfloat *)pData + positionSize;
        }
        else
        {
            pPosition = NULL;
            pColor = (GLvoid *)(sizeof(GLSLVertex1P1C::m_position));
        }
        
        glVertexAttribPointer(positionAttribute->GetLocation(), positionSize, GL_FLOAT, GL_FALSE, sizeof(GLSLVertex1P1C), pPosition);
        CheckError();
        
        glVertexAttribPointer(colorAttribute->GetLocation(), colorSize, GL_FLOAT, GL_FALSE, sizeof(GLSLVertex1P1C), pColor);
        CheckError();
    }
    
    void GLSLPerspectiveDrawing::InitializeUniforms(const map<string, GLRenderer::GLSLUniform *> *pUniforms) const
    {
        Log("Test");
    }
}