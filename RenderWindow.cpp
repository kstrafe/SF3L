////////////////////////////////////////////////////////////
//
// SF3L - Simple, Fast 3D Library
// Copyright © 2013 Kevin R. Stravers (macocio@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#include "RenderWindow.hpp"


namespace sf3
{

    RenderWindow::RenderWindow()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        // Depth clearing and testing:
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glClearDepth(1.0f);


//        glShadeModel(GL_SMOOTH);

        // Setting the matrix and perspective:
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f,(GLfloat)800/(GLfloat)600,0.1f,100.0f);
        glMatrixMode(GL_MODELVIEW);
    }


    RenderWindow::~RenderWindow()
    {}


    void RenderWindow::clear()
    {
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
    }


    void RenderWindow::clear(Color &color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
        clear();
    }


    void RenderWindow::setView(const sf3::View &view)
    {
        glRotatef(view.m_x_rotation, 1.f, 0.f, 0.f);
        glRotatef(view.m_y_rotation, 0.f, 1.f, 0.f);
        glRotatef(view.m_z_rotation, 0.f, 0.f, 1.f);

        sf::Vector3f position = view.getPosition();
        glTranslatef(-view.m_x_position, view.m_y_position, -view.m_z_position);
    }


    void RenderWindow::resetView()
    {
        glLoadIdentity();
    }

} // Namespace sf3
