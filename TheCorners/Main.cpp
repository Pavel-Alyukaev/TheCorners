#include "stdafx.h"
#include "Engine.h"

int main()
{
    // Объявляем экземпляр класса Engine
    Engine engine;

    engine.Init();

    // Вызываем функцию start
    engine.Start();

    // Останавливаем программу программу, когда движок остановлен
    return 0;
}
