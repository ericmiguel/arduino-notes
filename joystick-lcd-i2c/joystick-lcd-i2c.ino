#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define vermelho 11
#define verde 10
#define azul 9
#define x A0    // Saída analógica (Eixo X)
#define y A1    // Saída analógica (Eixo Y)
#define botao 2 // Saída digital do botão (Eixo Z)

#define lcd_n_col 16      // define o numero de colunas do display utilizado
#define lcd_n_lin 2       // define o numero de linhas do display utilizado
#define endereco_i2c 0x27 // endereço I2c (veja função obterEnderecoI2C)
LiquidCrystal_I2C lcd(endereco_i2c, lcd_n_col, lcd_n_lin);

int obterEnderecoI2C()
{
    Wire.begin();
    byte erro, endereco;
    int n_dispositivos = 0;
    for (endereco = 1; endereco < 127; endereco++)
    {
        Wire.beginTransmission(endereco);
        erro = Wire.endTransmission();
        if (erro == 0)
        {
            n_dispositivos++;
            return endereco;
        }
        else if (erro == 4)
        {
            Serial.println("Erro ao obter informação da conexão.");
            Serial.println("A rotina será interrompida.");
            exit(1);
        }
    }

    if (n_dispositivos == 0)
    {
        Serial.println("Nenhum dispositivo I2C encontrado.");
        Serial.println("A rotina será interrompida.");
        exit(1);
    }
}

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

void escreverTela(String msg, int linha, int coluna)
{
    lcd.clear();
    lcd.setCursor(linha, coluna);
    lcd.print(msg);
}

void setup()
{
    Serial.begin(9600);
    while (!Serial)
        ;

    // #################################################################################
    // Identificação da porta I2C
    // #################################################################################
    Serial.println("I2C Scanner");
    int endereco = obterEnderecoI2C();
    Serial.print("Endereço I2C (HEX): 0x");
    Serial.println(endereco, HEX);

    pinMode(vermelho, OUTPUT);
    pinMode(verde, OUTPUT);
    pinMode(azul, OUTPUT);
    pinMode(botao, INPUT_PULLUP);

    lcd.init();
    lcd.backlight();
    escreverTela("LCD operando!", 0, 0);

    delay(3000);
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
        escreverTela("analog: cima", 0, 0);
    }
    if (analogRead(x) == 1023)
    {
        Serial.println("direção: baixo");
        Verde();
        escreverTela("analog: baixo", 0, 0);
    }

    if (analogRead(y) == 0)
    {
        Serial.println("direção: direita");
        Azul();
        escreverTela("analog: direita", 0, 0);
    }
    if (analogRead(y) == 1023)
    {
        Serial.println("direção: esquerda");
        Vermelho();
        escreverTela("analog: esquerda", 0, 0);
    }

    if ((digitalRead(botao)) == 0)
    {
        Serial.println("botão pressionado");
        Ciano();
        escreverTela("analog: click!", 0, 0);
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
