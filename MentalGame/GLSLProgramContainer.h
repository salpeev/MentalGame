//
//  GLSLProgramContainer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 19.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "GLSLProgram.h"



namespace GLRenderer
{
    class GLSLProgramContainer
    {
    public:
        static const GLSLProgramContainer & SharedInstance()
        {
            static GLSLProgramContainer programContainer;
            return programContainer;
        }
        
        GLSLProgram * GetPositionColorProgram() const;
        GLSLProgram * GetPerspectiveProgram() const;
        
    private:
        GLSLProgramContainer();
        GLSLProgramContainer(const GLSLProgramContainer &);
        GLSLProgramContainer & operator= (const GLSLProgramContainer &);
        
        void LoadPositionColorProgram();
        void LoadPerspectiveProgram();
        
        GLSLProgram *m_positionColorProgram;
        GLSLProgram *m_perspectiveProgram;
    };
}
