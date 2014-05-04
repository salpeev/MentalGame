//
//  ProgramContainer.h
//  MentalGame
//
//  Created by Sergey Alpeev on 19.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Program.h"



namespace Renderer {
    
    class ProgramContainer {
    public:
        static const ProgramContainer & SharedInstance() {
            static ProgramContainer programContainer;
            return programContainer;
        }
        
        Program * GetPositionColorProgram() const;
        Program * GetPerspectiveProgram() const;
        Program * GetTextureProgram() const;
        
    private:
        ProgramContainer();
        ProgramContainer(const ProgramContainer &);
        ProgramContainer & operator= (const ProgramContainer &);
        
        void LoadPositionColorProgram();
        void LoadPerspectiveProgram();
        void LoadTextureProgram();
        
        Program *m_positionColorProgram;
        Program *m_perspectiveProgram;
        Program *m_textureProgram;
    };
}
