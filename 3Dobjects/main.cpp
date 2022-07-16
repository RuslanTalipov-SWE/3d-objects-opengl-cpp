#include <GL/freeglut.h>
#include <iostream>

GLdouble timer = 0; //задаем таймер

// Функция отрисовки
void drawCubeAndTriangle() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка буфера цвета и буфера глубины
    glPushMatrix(); // сохраняем текущие координаты
    glRotated(timer, 1, 1, 1); //функция вращения по таймеру
    glColor3f(0.0f, 0.0f, 1.0f); // цвет куба

    // Верхняя грань проволочного куба
    float scale = 1.5; //размер
    glBegin(GL_LINE_LOOP); // начало отрисовки
    glVertex3f(-scale, scale, scale);
    glVertex3f(-scale, scale, -scale);
    glVertex3f(scale, scale, -scale);
    glVertex3f(scale, scale, scale);
    glEnd(); // конец отрисовки

    // Нижняя грань проволочного куба
    glBegin(GL_LINE_LOOP); // начало отрисовки
    glVertex3f(-scale, -scale, scale);
    glVertex3f(-scale, -scale, -scale);
    glVertex3f(scale, -scale, -scale);
    glVertex3f(scale, -scale, scale);
    glEnd(); // конец отрисовки

    // Правая грань проволочного куба
    glBegin(GL_LINE_LOOP); // начало отрисовки
    glVertex3f(scale, -scale, scale);
    glVertex3f(scale, scale, scale);
    glVertex3f(scale, scale, -scale);
    glVertex3f(scale, -scale, -scale);
    glEnd(); // конец отрисовки

    // Левая грань проволочного куба
    glBegin(GL_LINE_LOOP); // начало отрисовки
    glVertex3f(-scale, -scale, scale);
    glVertex3f(-scale, scale, scale);
    glVertex3f(-scale, scale, -scale);
    glVertex3f(-scale, -scale, -scale);
    glEnd(); // конец отрисовки

    glBegin(GL_TRIANGLES); // начало отрисовки пирамиды

    // Передняя грань пирамиды
    glColor3f(0, 0, 1); // цвет грани
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Задняя грань пирамиды
    glColor3f(1, 1, 0); // цвет грани
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Левая грань пирамиды
    glColor3f(1, 0, 1); // цвет грани
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Правая грань пирамиды
    glColor3f(0, 1, 1); // цвет грани
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glEnd(); // конец отрисовки

    // Нижняя грань пирамиды
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0); // цвет грани
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd(); // конец отрисовки

    glPopMatrix(); // возвращаемся к старой системе координат
    glutSwapBuffers(); // обмен буферов
}

// Функция анимации
void animate(int val) {
    timer++;
    if (timer >= 360) timer = 0;
    glutPostRedisplay(); // вызов функции перерисовки текущего окна
    glutTimerFunc(0, animate, 1); // задает функцию animate, вызываемую по таймеру
}

// Функция инициализации
void initialize() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // цвет фона
    glClearDepth(1.0f); // очистка буфера глубины
    glEnable(GL_DEPTH_TEST); // функция проверĸи глубины
    glMatrixMode(GL_PROJECTION); // режим матрицы проекций
    glLoadIdentity(); // сброс матрицы на единичную
    glOrtho(-3, 3, -3, 3, -10.0, 10.0); // установка ортографической системы координат
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // инициализация окна
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // установка режима отображения
    glutInitWindowSize(600, 600); // размер окна
    glutInitWindowPosition(200, 200); // положение окна
    glutCreateWindow("Geometry"); // создание окна
    glutDisplayFunc(drawCubeAndTriangle); // функция отрисовки
    initialize(); // инициализация
    glutTimerFunc(0, animate, 1); // функция таймера
    glutMainLoop(); // процедура обработки событий
    return 0;
}
