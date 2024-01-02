#define vermelho 11
#define verde 10
#define azul 9
#define x A0    // Saída analógica (Eixo X)
#define y A1    // Saída analógica (Eixo Y)
#define botao 2 // Saída digital do botão (Eixo Z)

void Vermelho()
{
    digitalWrite(azul, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(vermelho, HIGH);
}
void Verde()
{
    digitalWrite(vermelho, LOW);
    digitalWrite(azul, LOW);
    digitalWrite(verde, HIGH);
}
void Azul()
{
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(azul, HIGH);
}
void Branco()
{
    digitalWrite(azul, HIGH);
    digitalWrite(vermelho, HIGH);
    digitalWrite(verde, HIGH);
}
void Magenta()
{
    digitalWrite(verde, LOW);
    digitalWrite(azul, HIGH);
    digitalWrite(vermelho, HIGH);
}
void Ciano()
{
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, HIGH);
    digitalWrite(azul, HIGH);
}

void setup()
{
    Serial.begin(9600);
    while (!Serial)
        ;
    pinMode(vermelho, OUTPUT);
    pinMode(verde, OUTPUT);
    pinMode(azul, OUTPUT);
    pinMode(botao, INPUT_PULLUP); // HIGH quando o botão não estiver pressionado
}

void loop()
{
    // Notas:
    // > declarações switch...case não permitiram a leitura em 'tempo real' das
    // entradas analógicas, então declaraçóes 'if' (sem else if), foram as melhores

    if (analogRead(x) == 0)
    {
        Serial.println("direção: cima");
        Magenta();
    }
    if (analogRead(x) == 1023)
    {
        Serial.println("direção: baixo");
        Verde();
    }

    if (analogRead(y) == 0)
    {
        Serial.println("direção: direita");
        Azul();
    }
    if (analogRead(y) == 1023)
    {
        Serial.println("direção: esquerda");
        Vermelho();
    }

    if ((digitalRead(botao)) == 0)
    {
        Serial.println("botão pressionado");
        Ciano();
        delay(500);

        if ((digitalRead(botao)) == 0)
        {
            Branco();

            if ((digitalRead(botao)) == 0)
            {
                Serial.println("------------------------------------");
                Serial.print("Eixo X: ");
                Serial.println(analogRead(x));
                Serial.print("Eixo Y: ");
                Serial.println(analogRead(y));
                Serial.print("Leitura do botão: ");
                Serial.println(digitalRead(botao));
                Serial.println("------------------------------------");
            }
        }
    }
}
