#include "Application.h"

namespace applicationManager{

    void StartGame(){
        //Add the first state of the game to the menu state.
        m_manager.NewPanel(std::make_unique<MenuState>(m_standardWindow));

        //Initilize the first panel
        m_manager.GetCurrentPanel().InitilizeGameState();

        while(m_standardWindow.isOpen()){
            sf::Event event;
            while (m_standardWindow.pollEvent(event)){

                if (event.type == sf::Event::Closed){
                    // Someone closed the window- bye
                    m_standardWindow.close();
                }
           }
            // Checks if it is time for a new Panel to be processed.
            m_manager.InitilizeNewPanel();
            // Updates the assets in the current panel.
            m_manager.Update();
            // Draws all sprites in the current panel.
            m_manager.draw();
        }
    }

    void MoveToNextPanel(){
        // Set the current panel m_next to true and moves to the next panel in queue.
        m_manager.GetCurrentPanel().SetNextPanel(true);

        m_manager.InitilizeNewPanel();
    }

    void AddPanel(const GameState::m_states state){
        if(state == GameState::m_states::MenuState){
         m_manager.NewPanel(std::make_unique<MenuState>(m_standardWindow));
         MoveToNextPanel();
        }

        if(state == GameState::m_states::PlayState){
            m_manager.NewPanel(std::make_unique<PlayState>(m_standardWindow));
            MoveToNextPanel();
        }
    }

    void AddAndSaveCurrentPanel(const GameState::m_states state){
        // Depending on the enum passed queue the corresponding state the queue
        // and requeue the current panel if need be (i.e if the game has been paused).
        if(state == GameState::m_states::MenuState){
            m_manager.NewPanel(std::make_unique<MenuState>(m_standardWindow));
            MoveToNextPanel();
        }

        if(state == GameState::m_states::PlayState){
            m_manager.NewPanel(std::make_unique<PlayState>(m_standardWindow));
            MoveToNextPanel();
        }
        if(state == GameState::m_states::PauseState){
           m_manager.NewPanel(std::make_unique<pauseState>(m_standardWindow));
           // If the game is paused then the current panel needs to suspended
           //and requened for later use.
           m_manager.RequeuePanel();

        }
    }
}
