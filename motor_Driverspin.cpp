// Motor control pins
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

char command;
bool forwardPressed = false;
bool leftPressed = false;
bool rightPressed = false;
bool backwardPressed = false;

void setup() {
  // Initialize motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start Serial communication for bluetooth
  Serial.begin(9600);//default
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();

    
    if (command == 'F') {
      forwardPressed = true;
    }
    else if (command == 'B') {
      backwardPressed = true;
    }
    else if (command == 'L') {
      leftPressed = true;
    }
    else if (command == 'R') {
      rightPressed = true;
    }
    else if (command == 'S') { // Stop
      stopMotors();
    }
  }

 
  if (forwardPressed && leftPressed) {
    forwardLeft();
  }
  else if (forwardPressed && rightPressed) {
    forwardRight();
  }
  else if (backwardPressed && leftPressed) {
    backwardLeft();
  }
  else if (backwardPressed && rightPressed) {
    backwardRight();
  }
  else if (forwardPressed) {
    forward();
  }
  else if (backwardPressed) {
    backward();
  }
  else if (leftPressed) {
    left();
  }
  else if (rightPressed) {
    right();
  }

 
  forwardPressed = false;
  backwardPressed = false;
  leftPressed = false;
  rightPressed = false;
}


void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forwardLeft() {
  // Forward-left: Left motor forward, Right motor backward
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  
  digitalWrite(IN4, HIGH);
}

void forwardRight() {
  // Forward-right: Left motor forward, Right motor forward
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backwardLeft() {
  // Backward-left: Left motor backward, Right motor forward
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backwardRight() {
  // Backward-right: Left motor backward, Right motor backward
  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
