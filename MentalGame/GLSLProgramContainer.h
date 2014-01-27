//
//  GLSLProgramContainer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 19.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Program.h"



namespace Renderer
{
    class GLSLProgramContainer
    {
    public:
        static const GLSLProgramContainer & SharedInstance()
        {
            static GLSLProgramContainer programContainer;
            return programContainer;
        }
        
        Program * GetPositionColorProgram() const;
        Program * GetPerspectiveProgram() const;
        
    private:
        GLSLProgramContainer();
        GLSLProgramContainer(const GLSLProgramContainer &);
        GLSLProgramContainer & operator= (const GLSLProgramContainer &);
        
        void LoadPositionColorProgram();
        void LoadPerspectiveProgram();
        
        Program *m_positionColorProgram;
        Program *m_perspectiveProgram;
    };
}
