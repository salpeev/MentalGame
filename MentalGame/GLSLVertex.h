//
//  GLSLVertex.h
//  MentalGame
//
//  Created by Sergey Alpeev on 29.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLPoint.h"
#include "GLColor.h"



namespace GLRenderer
{
    class GLSLVertex
    {
    public:
        virtual GLint GetSizeAtIndex(GLint index) const = 0;
        virtual GLint GetMembersCount() const = 0;
        virtual GLuint GetByteSize() const = 0;
    };
    
    
    
    class GLSLVertex1P: public GLSLVertex
    {
    public:
        GLSLVertex1P();
        GLSLVertex1P(GLPoint position);
        
        void SetPosition(GLPoint position);
        
        GLPoint GetPosition() const;
        
        GLint GetSizeAtIndex(GLint index) const;
        GLint GetMembersCount() const;
        GLuint GetByteSize() const;
        
    private:
        GLPoint m_position;
    };
    
    
    
    class GLSLVertex1C: public GLSLVertex
    {
    public:
        GLSLVertex1C();
        GLSLVertex1C(GLColor color);
        
        void SetColor(GLColor color);
        
        GLColor GetColor() const;
        
        GLint GetSizeAtIndex(GLint index) const;
        GLint GetMembersCount() const;
        GLuint GetByteSize() const;
        
    private:
        GLColor m_color;
    };
    
    
    
    class GLSLVertex1P1C: public GLSLVertex
    {
    public:
        GLSLVertex1P1C();
        GLSLVertex1P1C(GLPoint position, GLColor color);
        
        void SetPosition(GLPoint position);
        void SetColor(GLColor color);
        
        GLPoint GetPosition() const;
        GLColor GetColor() const;
        
        GLint GetSizeAtIndex(GLint index) const;
        GLint GetMembersCount() const;
        GLuint GetByteSize() const;
        
    private:
        GLSLVertex1P m_position;
        GLSLVertex1C m_color;
    };
}
