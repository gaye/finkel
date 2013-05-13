
struct KeyboardInput {
  1: string text;
}


struct MouseInput {
  1: i32 x;
  2: i32 y;
  3: bool doubleClick;
}


union UserInput {
  1: KeyboardInput keyboardInput;
  2: MouseInput mouseInput;
}


service Finkel {
  /**
   * @param username Magic Online username to be used for login.
   * @param password Magic Online password to be used for login.
   * @return Whether or not Magic Online started successfully.
   */
  bool Start(1: string username, 2: string password);


  /**
   * @return Whether or not Magic Online stopped successfully.
   */
  bool Stop();


  /**
   * @return Screenshot of Magic Online.
   */
  list<list<byte>> TakeScreenshot();


  /**
   * @return Whether or not the input sequence succeeded.
   */
  bool ProcessUserInput(1: list<UserInput> inputSequence);
}

