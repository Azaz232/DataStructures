#pragma once


/// \brief  Checks whether the string is a number
/// \param input Users input
/// \return True if the string is a number
bool IsNumber(const std::string& input);

/// \brief Gets input from the user
/// \param message Prompt to display to the user
/// \return The number entered by the user
int GetInput(const std::string& message);

/// \brief Gets user input
/// \param message Message to display to the user
/// \return The string input provided by the user
std::string GetInputString(const std::string& message);

/// \brief Gets user input for the size
/// \param message Prompt to display to the user
/// \return A positive number entered by the user
int PositiveSize(const std::string& message);
