#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Green Square");

    // Create a rectangle (square) shape
    sf::RectangleShape square(sf::Vector2f(100.0f, 100.0f)); // 100x100 square
    square.setFillColor(sf::Color::Green); // Set fill color to green
    square.setPosition(350.0f, 250.0f); // Center the square in the window

    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Close the window if the close button is clicked
        }

        // Clear the window with a black background
        window.clear(sf::Color::Black);

        // Draw the square
        window.draw(square);

        // Display the contents of the window
        window.display();
    }

    return 0;
}