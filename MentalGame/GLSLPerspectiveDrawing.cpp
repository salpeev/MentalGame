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
    void GLSLPerspectiveDrawing::SetProjectionMatrix(GLSLMatrix4 &rProjectionMatrix) const
    {
        GLSLUniform *projectionUniform = GetUniformByName("u_projection");
        projectionUniform->SetMatrix4(rProjectionMatrix);
    }
    
    GLSLMatrix4 GLSLPerspectiveDrawing::GetProjectionMatrix() const
    {
        GLSLUniform *projectionUniform = GetUniformByName("u_projection");
        GLSLMatrix4 projectionMatrix = projectionUniform->GetMatrix4();
        return projectionMatrix;
    }
    
    void GLSLPerspectiveDrawing::SetModelviewMatrix(GLSLMatrix4 &rModelviewMatrix) const
    {
        GLSLUniform *modelviewUniform = GetUniformByName("u_modelview");
        modelviewUniform->SetMatrix4(rModelviewMatrix);
    }
    
    GLSLMatrix4 GLSLPerspectiveDrawing::GetModelviewMatrix() const
    {
        GLSLUniform *modelviewUniform = GetUniformByName("u_modelview");
        GLSLMatrix4 modelviewMatrix = modelviewUniform->GetMatrix4();
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
    
    void GLSLPerspectiveDrawing::InitializeAttributes(GLvoid *pData) const
    {
        GLSLAttribute *positionAttribute = GetAttributeByName("a_position");
        GLSLAttribute *colorAttribute = GetAttributeByName("a_color");
        
        // TODO: Probably should be enabled in another place. Here should be initialized only if enabled.
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
        
        glVertexAttribPointer(positionAttribute->GetLocation(), positionSize, GL_FLOAT, GLSL_FALSE, sizeof(GLSLVertex1P1C), pPosition);
        CheckError();
        
        glVertexAttribPointer(colorAttribute->GetLocation(), colorSize, GL_FLOAT, GLSL_FALSE, sizeof(GLSLVertex1P1C), pColor);
        CheckError();
    }
    
    void GLSLPerspectiveDrawing::InitializeUniforms() const
    {
        GLSLMatrix4 projectionMatrix = GLSLMatrix4::Frustum(-2.0f, 2.0f, -2.0f, 2.0f, 4.0f, 10.0f);
        SetProjectionMatrix(projectionMatrix);
        
        GLSLMatrix4 modelviewMatrix;
        SetModelviewMatrix(modelviewMatrix);
    }
}