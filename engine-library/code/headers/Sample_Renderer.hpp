
// This is free code released into the public domain.
// Drafted by 脕ngel in January 2019.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu


/**********************************************************************
*Project           : EngineTask
*
*Author : Jorge C醩edas
*
*Starting date : 24/06/2020
*
*Ending date : 03/07/2020
*
*Purpose : Creating a 3D engine that can be used later on for developing a playable demo, with the engine as static library
*
**********************************************************************/

#pragma once

#include <memory>
#include <string>
#include <internal/declarations.hpp>

namespace engine
{

    class Window;

    class Sample_Renderer
    {

        // Se crea un puntero a Render_Node porque al usar una declaraci贸n adelantada
        // para no exportar dependencias con esta cabecera, solo se pueden definir
        // punteros o referencias a los tipos declarados de modo adelantado.

        std::unique_ptr< glt::Render_Node > renderer;

        Window * window;

    public:

        Sample_Renderer(Window & given_window);

        /** En este caso es necesario definir expl铆citamente el destructor en el archivo
          * de implementaci贸n (CPP) para que el compilador pueda destruir el Render_Node.
          * Si se deja que el compilador cree un destructor por defecto en el programa
          * que use el engine, como solo tendr谩 una declaraci贸n adelantada, no sabr谩 c贸mo
          * destruirlo y ello dar谩 lugar a un error de compilaci贸n.
          */
       ~Sample_Renderer();

        void render ();

    };

}
