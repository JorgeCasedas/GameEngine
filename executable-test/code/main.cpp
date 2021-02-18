
// Code released into the public domain
// in January 2019
// by Ángel

#include <Window.hpp>
#include <Sample_Renderer.hpp>
#include <Level.hpp>
#include <Entity.hpp>
#include <Component.hpp>
#include <Transform.hpp>
#include <EntityTask.hpp>
#include <RenderTask.hpp>
#include <Kernel.hpp>
#include <InputTask.hpp>

#include <MessageBus.hpp>
#include <PlayerMovementComponent.hpp>

using namespace engine;

int main ()
{
    // Se crea una ventana:

    Window window("TEST", 1280, 720/*, true*/);

    window.enable_vsync ();

  /*

    shared_ptr<Level> level(new Level(window));

    shared_ptr<EntityTask> entityTask(new EntityTask());
    shared_ptr<RenderTask> renderTask(new RenderTask(*level));
    shared_ptr<Kernel> kernel( new Kernel(entityTask.get(), renderTask.get()));

    shared_ptr<Entity> testEntity(new Entity("test", *level, "cube.obj", *entityTask));
    
  */


    //It is better using make_shared instead of new Class, the allocations get reduced from 2 dynamic memory to 1 single allocation

    shared_ptr<Level> level = make_shared<Level>(window);
    level->TranslateCamera(0, 12, 4);
    level->RotateCamerta(-1, 0, 0);
    

    shared_ptr<MessageBus> messageBus = make_shared<MessageBus>();

    shared_ptr<EntityTask> entityTask = make_shared<EntityTask>();
    shared_ptr<RenderTask> renderTask = make_shared<RenderTask>(*level);
    shared_ptr<InputTask> inputTask = make_shared<InputTask>(messageBus.get());
    shared_ptr<Kernel> kernel = make_shared<Kernel>(entityTask.get(), renderTask.get(), inputTask.get(), messageBus.get());

    //Entities
    shared_ptr<Entity> character = make_shared <Entity>("character", *level, "../../assets/Stich.obj", *entityTask);
    shared_ptr<PlayerMovementComponent> movComponent = make_shared<PlayerMovementComponent>(*messageBus, 5,"../../assets/wallHit.vaw"); 
    
    character->AddComponent(movComponent.get());

    shared_ptr<Entity> playerCharacterIndicator = make_shared <Entity>("indicator", *level, "../../assets/Cube.obj", *entityTask);
    playerCharacterIndicator->SetScale(0.2f, 0.5f, 0.2f);
    playerCharacterIndicator->Translate(0, 2, 0);

    character->AddChild(*(playerCharacterIndicator.get()));
    
    vector<Entity*> enemies;

    shared_ptr<Entity> enemy1 = make_shared <Entity>("enemy1", *level, "../../assets/Cube.obj", *entityTask);
    enemy1->Translate(6, 0, 6);
    enemies.push_back(enemy1.get());

    shared_ptr<Entity> enemy2 = make_shared <Entity>("enemy2", *level, "../../assets/Cube.obj", *entityTask);
    enemy2->Translate(-6, 0, -6);
    enemies.push_back(enemy2.get());

    shared_ptr<Entity> enemy3 = make_shared <Entity>("enemy3", *level, "../../assets/Cube.obj", *entityTask);
    enemy3->Translate(-6, 0, 6);
    enemies.push_back(enemy3.get());

    shared_ptr<Entity> enemy4 = make_shared <Entity>("enemy4", *level, "../../assets/Cube.obj", *entityTask);
    enemy4->Translate(6, 0, -6);
    enemies.push_back(enemy4.get());

    //Enviroment
    shared_ptr<Entity> wall1 = make_shared <Entity>("wall1", *level, "../../assets/Cube.obj", *entityTask);
    wall1->SetScale(0.2f, 0.5f, 14.f);
    wall1->Translate(7, 0, 0);

    shared_ptr<Entity> wall2 = make_shared <Entity>("wall2", *level, "../../assets/Cube.obj", *entityTask);
    wall2->SetScale(0.2f, 0.5f, 14.f);
    wall2->Translate(-7, 0, 0);

    shared_ptr<Entity> wall3 = make_shared <Entity>("wall3", *level, "../../assets/Cube.obj", *entityTask);
    wall3->SetScale(14.f, 0.5f, 0.2f);
    wall3->Translate(0, 0, 7);

    shared_ptr<Entity> wall4 = make_shared <Entity>("wall4", *level, "../../assets/Cube.obj", *entityTask);
    wall4->SetScale(14.f, 0.5f, 0.2f);
    wall4->Translate(0, 0, -7);

    movComponent->SetMovementLimits(-6.5, 6.5, 6.5, -6.5);

    // Se ejecuta el bucle principal:

    bool exit = false;

    while (!exit)
    {
        Window::Event event;

        while (window.poll (event))
        {
            switch (event.type)
            {
                case Window::Event::CLOSE:
                {
                    exit = true;
                    break;
                }

                case Window::Event::KEY_PRESSED:
                {
                    if (event.data.keyboard.key_code == Keyboard::KEY_ESCAPE)
                    {
                        exit = true;
                    }

                    break;
                }
            }
        }
        
        float playerX;
        float playerY;
        float playerZ;

        float enemyX;
        float enemyY;
        float enemyZ;

        character->GetPosition(playerX, playerY, playerZ);

        //Enemy movement
        for (int i = 0; i < enemies.size(); i++)
        {
            //Get normalized Vector
            enemies[i]->GetPosition(enemyX, enemyY, enemyZ);
            float newX = enemyX - playerX;
            float newY = enemyY - playerY;
            float newZ = enemyZ - playerZ;
            float module = -sqrtf((newX * newX) + (newY * newY) + (newZ * newZ)); //using floats for efficiency
            if (module > -0.8f)
            {
                //Reset Game
                character->SetPosition(0, 0, 0);

                enemies[0]->SetPosition(6, 0, 6);
                enemies[1]->SetPosition(-6, 0, -6);
                enemies[2]->SetPosition(-6, 0, 6);
                enemies[3]->SetPosition(6, 0, -6);
                break;
            }

            enemies[i]->Translate(newX/module * 0.03f , newY/module * 0.03f, newZ/module * 0.03f);
        }

        kernel->Update();
    }

    return 0;
}
