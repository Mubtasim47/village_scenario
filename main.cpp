#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat
    x_left_cloud,
    x_right_cloud,
    y_sun,
    y_ballon,
    x_bird,
    y_bird;

int cloud_state = -1;

void timer(int);

void drawSunRays(float r, float x_center, float y_center) {
    int deg = 0;
    float theta, x0, y0, x1, y1;
    glLineWidth(1.5);
    glBegin(GL_LINES);
    while(deg <= 360) {
        // theta values in radian
        theta = (deg * M_PI) / 180;
        x0 = x_center + (r + 1)*cos(theta);
        y0 = y_center + (r + 1)*sin(theta);
        x1 = x_center + (r + 3)*cos(theta);
        y1 = y_center + (r + 3)*sin(theta);
        glVertex2f(x0, y0);
        glVertex2f(x1, y1);
        deg += 20;
    }
    glEnd();
}

void drawCircle(float r, float x_center, float y_center) {
    int deg = 0;
    float theta, x, y;
    glPointSize(4);
    glBegin(GL_POLYGON);

    while(deg < 360) {
        // theta values in radian
        theta = (deg * M_PI) / 180;
        x = x_center + r*cos(theta);
        y = y_center + r*sin(theta);
        glVertex2f(x, y);
        deg++;
    }
    glEnd();
}

float _angle = 30.0f;
float _cameraAngle = 0.0f;

void display(void)
{
    /* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);


    /* ---------
        GRASS
    ------------ */

    glColor3f(0.137255f, 0.556863f, 0.137255f);
    glBegin(GL_TRIANGLES);

    glVertex2f(25.0f, 15.0f);
    glVertex2f(26.0f, 18.0f);
    glVertex2f(27.0f, 15.0f);
    glVertex2f(27.0f, 15.0f);
    glVertex2f(28.0f, 19.0f);
    glVertex2f(29.0f, 15.0f);

    glVertex2f(7.0f, 45.0f);
    glVertex2f(8.0f, 48.0f);
    glVertex2f(10.0f, 45.0f);
    glVertex2f(10.0f, 45.0f);
    glVertex2f(11.0f, 49.0f);
    glVertex2f(12.0f, 45.0f);

    glVertex2f(48.0f, 26.0f);
    glVertex2f(50.0f, 30.0f);
    glVertex2f(51.0f, 26.0f);
    glVertex2f(51.0f, 26.0f);
    glVertex2f(52.0f, 29.0f);
    glVertex2f(53.0f, 26.0f);

    glVertex2f(45.0f, 40.0f);
    glVertex2f(46.0f, 43.0f);
    glVertex2f(47.0f, 40.0f);
    glVertex2f(47.0f, 40.0f);
    glVertex2f(47.5f, 44.0f);
    glVertex2f(49.0f, 40.0f);

    glEnd();

    /* ----------
        CLOUDS
    ------------- */
    glColor3ub(216, 242, 255);
    drawCircle(2, 9+x_left_cloud, 100);
    drawCircle(2, 12+x_left_cloud, 100);
    drawCircle(2, 15+x_left_cloud, 100);
    drawCircle(2, 18+x_left_cloud, 100);
    drawCircle(2, 10+x_left_cloud, 98.5);
    drawCircle(2, 13+x_left_cloud, 98.5);
    drawCircle(2, 13+x_left_cloud, 98.5);
    drawCircle(2, 16+x_left_cloud, 98.5);

    drawCircle(2, 69+x_right_cloud, 110);
    drawCircle(2, 72+x_right_cloud, 110);
    drawCircle(2, 75+x_right_cloud, 110);
    drawCircle(2, 78+x_right_cloud, 110);
    drawCircle(2, 70+x_right_cloud, 108.5);
    drawCircle(2, 73+x_right_cloud, 108.5);
    drawCircle(2, 73+x_right_cloud, 108.5);
    drawCircle(2, 76+x_right_cloud, 108.5);



    /* -------
        SUN
    ---------- */
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(4.5, 35, 67+y_sun);
    drawSunRays(4.5, 35, 67+y_sun);

    /* ------------
        MOUNTAINS
    --------------- */

    glColor3f(0.529412f, 0.529412f, 0.529412f);
    glBegin(GL_TRIANGLES);

    glVertex2f(12, 56);
    glVertex2f(18, 73);
    glVertex2f(25, 59);

    glVertex2f(20, 58);
    glVertex2f(28, 74);
    glVertex2f(39, 57);

    glVertex2f(31.5, 56);
    glVertex2f(40, 75);
    glVertex2f(56, 56);

    glVertex2f(46, 60);
    glVertex2f(55, 75);
    glVertex2f(64, 58);

    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);
    glVertex2f(18, 73);
    glVertex2f(15.878, 67);
    glVertex2f(17, 65);
    glVertex2f(18, 67);
    glVertex2f(20, 65);
    glVertex2f(21, 67);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(28, 74);
    glVertex2f(26, 70);
    glVertex2f(27, 68.7);
    glVertex2f(27.7, 70);
    glVertex2f(29, 68);
    glVertex2f(30.6, 70);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(40, 75);
    glVertex2f(37.767, 70);
    glVertex2f(39, 69);
    glVertex2f(40, 70);
    glVertex2f(42, 69);
    glVertex2f(43, 70);
    glVertex2f(44.97, 69.15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(55, 75);
    glVertex2f(52, 70);
    glVertex2f(53, 69);
    glVertex2f(55, 70);
    glVertex2f(56, 69);
    glVertex2f(57.8, 70);
    glEnd();

    /* ---------
        RIVER
    ------------ */
    glColor3f(0.74902f, 0.847059f, 0.977059f);

    glBegin(GL_POLYGON);
    glVertex2f(39, 56);
    glVertex2f(40, 53);
    glVertex2f(40, 48);
    glVertex2f(37, 43);
    glVertex2f(30, 43);
    glVertex2f(33, 48);
    glVertex2f(33, 53);
    glVertex2f(32, 56);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(30, 43);
    glVertex2f(37, 43);
    glVertex2f(36, 38);
    glVertex2f(37, 34);
    glVertex2f(30, 34);
    glVertex2f(29, 38);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(37, 34);
    glVertex2f(40, 31);
    glVertex2f(41, 28);
    glVertex2f(43, 25);
    glVertex2f(36, 25);
    glVertex2f(34, 28);
    glVertex2f(33, 31);
    glVertex2f(30, 34);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(43, 25);
    glVertex2f(44, 23);
    glVertex2f(47, 20);
    glVertex2f(48, 17);
    glVertex2f(41, 17);
    glVertex2f(40, 20);
    glVertex2f(37, 23);
    glVertex2f(36, 25);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(41, 17);
    glVertex2f(48, 17);
    glVertex2f(47, 13);
    glVertex2f(47, 10);
    glVertex2f(48, 6);
    glVertex2f(41, 6);
    glVertex2f(40, 10);
    glVertex2f(40, 13);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(48, 6);
    glVertex2f(47, 3);
    glVertex2f(45, 0);
    glVertex2f(38, 0);
    glVertex2f(40, 3);
    glVertex2f(41, 6);
    glEnd();


    /* ---------
        HILLS
    ------------ */

    glColor3f(0.137255f, 0.456863f, 0.177255f);
    glBegin(GL_POLYGON);


    glVertex2f(10.0f, 55.0f);
    glVertex2f(15.0f, 60.0f);
    glVertex2f(17.0f, 59.0f);
    glVertex2f(20.0f, 61.0f);
    glVertex2f(25.0f, 59.0f);
    glVertex2f(36.0f, 64.0f);
    glVertex2f(39.0f, 60.0f);
    glVertex2f(44.0f, 62.0f);
    glVertex2f(49.0f, 61.0f);
    glVertex2f(52.0f, 62.0f);
    glVertex2f(54.0f, 63.0f);
    glVertex2f(60.0f, 61.0f);
    glVertex2f(64.0f, 58.0f);
    glVertex2f(65.0f, 55.0f);

    glEnd();

    /* ------------------
        LEFT SIDE TREE
    --------------------- */
    glColor3f(0.137255f, 0.556863f, 0.137255f);
    drawCircle(3, 11, 27);
    drawCircle(3, 16, 27);
    drawCircle(3, 20, 29);
    drawCircle(3, 14, 29);
    drawCircle(3, 12, 29);
    drawCircle(3, 7, 29);
    drawCircle(3, 16, 31);
    drawCircle(3, 13, 31);
    drawCircle(3, 10, 31);


    glColor3f(0.81f, 0.71f, 0.23f);
    glBegin(GL_POLYGON);
    glVertex2f(13.0f, 27.0f);
    glVertex2f(14.0f, 25.0f);
    glVertex2f(14.0f, 23.0f);
    glVertex2f(12.0f, 23.0f);
    glVertex2f(12.0f, 25.0f);
    glVertex2f(11.0f, 27.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(12.0f, 23.0f);
    glVertex2f(14.0f, 23.0f);
    glVertex2f(12.0f, 20.0f);
    glVertex2f(12.0f, 10.0f);
    glVertex2f(10.0f, 10.0f);
    glVertex2f(10.0f, 20.0f);
    glEnd();

    glColor3f(0.83f, 0.53f, 0.10f);

    glBegin(GL_POLYGON);
    glVertex2f(10.0f, 10.0f);
    glVertex2f(12.0f, 10.0f);
    glVertex2f(14.0f, 9.0f);
    glVertex2f(13.0f, 8.0f);
    glVertex2f(11.0f, 8.0f);
    glVertex2f(10.0f, 9.0f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glVertex2f(10.0f, 10.0f);
    glVertex2f(7.0f, 9.0f);
    glVertex2f(10.0f, 9.0f);
    glVertex2f(10.0f, 9.0f);
    glVertex2f(9.0f, 8.0f);
    glVertex2f(11.0f, 8.0f);
    glVertex2f(11.0f, 8.0f);
    glVertex2f(12.0f, 7.0f);
    glVertex2f(13.0f, 8.0f);
    glVertex2f(13.0f, 8.0f);
    glVertex2f(16.0f, 8.0f);
    glVertex2f(14.0f, 9.0f);
    glEnd();


    /* --------------
        LEFT HOUSE
    ----------------- */
    glBegin(GL_QUADS);
    glColor3f(0.52f, 0.27f, 0.47f);
    glVertex2f(18.0f, 45.0f);
    glVertex2f(20.0f, 45.0f);
    glVertex2f(20.0f, 40.0f);
    glVertex2f(18.0f, 40.0f);

    glVertex2f(21.0f, 48.0f);
    glVertex2f(23.0f, 48.0f);
    glVertex2f(20.0f, 45.0f);
    glVertex2f(18.0f, 45.0f);

    glColor3f(0.52f, 0.37f, 0.36f);
    glVertex2f(20.0f, 45.0f);
    glVertex2f(28.0f, 45.0f);
    glVertex2f(28.0f, 40.0f);
    glVertex2f(20.0f, 40.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(22.0f, 44.0f);
    glVertex2f(24.0f, 44.0f);
    glVertex2f(24.0f, 40.0f);
    glVertex2f(22.0f, 40.0f);
    glVertex2f(25.0f, 43.0f);
    glVertex2f(27.0f, 43.0f);
    glVertex2f(27.0f, 41.0f);
    glVertex2f(25.0f, 41.0f);
    glVertex2f(18.5f, 44.0f);
    glVertex2f(19.5f, 44.0f);
    glVertex2f(19.5f, 43.0f);
    glVertex2f(18.5f, 43.0f);

    glEnd();

    glColor3f(0.52f, 0.37f, 0.36f);
    glBegin(GL_TRIANGLES);
    glVertex2f(20.0f, 45.0f);
    glVertex2f(23.0f, 48.0f);
    glVertex2f(28.0f, 45.0f);
    glEnd();

    glColor3f(0.9f, 0.9f, 0.9f);

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glVertex2f(18.0f, 45.0f);
    glVertex2f(28.0f, 45.0f);
    glVertex2f(18.0f, 45.0f);
    glVertex2f(21.0f, 48.0f);
    glVertex2f(23.0f, 48.0f);
    glVertex2f(28.0f, 45.0f);
    glVertex2f(20.0f, 45.0f);
    glVertex2f(23.0f, 48.0f);
    glVertex2f(20.0f, 45.0f);
    glVertex2f(23.0f, 48.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(23.0f, 44.0f);
    glVertex2f(23.0f, 40.0f);
    glVertex2f(25.0f, 42.0f);
    glVertex2f(27.0f, 42.0f);
    glVertex2f(26.0f, 41.0f);
    glVertex2f(26.0f, 43.0f);
    glVertex2f(19.0f, 43.0f);
    glVertex2f(19.0f, 44.0f);
    glEnd();

    /* ------------------
        RIGHT SIDE TREE
    --------------------- */
    glColor3f(0.137255f, 0.556863f, 0.137255f);
    glBegin(GL_TRIANGLES);
    glVertex2f(60.0f, 46.0f);
    glVertex2f(62.0f, 48.0f);
    glVertex2f(64.0f, 46.0f);
    glVertex2f(58.0f, 43.0f);
    glVertex2f(62.0f, 46.0f);
    glVertex2f(67.0f, 43.0f);
    glVertex2f(56.0f, 40.0f);
    glVertex2f(62.0f, 43.0f);
    glVertex2f(69.0f, 40.0f);
    glVertex2f(54.0f, 36.0f);
    glVertex2f(62.0f, 40.0f);
    glVertex2f(70.0f, 36.0f);
    glEnd();

    glColor3f(0.81f, 0.71f, 0.23f);
    glBegin(GL_QUADS);
    glVertex2f(60.5f, 36.0f);
    glVertex2f(63.5f, 36.0f);
    glVertex2f(63.5f, 24.0f);
    glVertex2f(60.5f, 24.0f);
    glEnd();

    glColor3f(0.83f, 0.53f, 0.10f);
    glBegin(GL_POLYGON);

    glVertex2f(60.5f, 24.0f);
    glVertex2f(63.5f, 24.0f);
    glVertex2f(66.5f, 21.0f);
    glVertex2f(64.5f, 22.0f);
    glVertex2f(62.5f, 22.0f);
    glVertex2f(61.5f, 23.0f);
    glVertex2f(57.5f, 22.0f);
    glVertex2f(59.5f, 23.0f);
    glEnd();

    /* ----------
        BALLON
    ------------- */
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(3, 74.5, 54.6 + y_ballon);

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.2);
    glBegin(GL_LINES);
    glVertex2f(73.0f, 52.0f + y_ballon);
    glVertex2f(74.5f, 48.0f + y_ballon);
    glVertex2f(76.0f, 52.0f + y_ballon);
    glVertex2f(74.5f, 48.0f + y_ballon);
    glEnd();

    glColor3f(0.90f, 0.91f, 0.98f);
    glBegin(GL_QUADS);
    glVertex2f(73.0f, 48.0f + y_ballon);
    glVertex2f(76.0f, 48.0f + y_ballon);
    glVertex2f(76.0f, 47.0f + y_ballon);
    glVertex2f(73.0f, 47.0f + y_ballon);
    glEnd();

    /* --------------
        RIGHT HOUSE
    ----------------- */
    glColor3f(0.89f, 0.47f, 0.20f);
    glBegin(GL_QUADS);
    glVertex2f(73.0f, 42.0f);
    glVertex2f(84.0f, 42.0f);
    glVertex2f(84.0f, 38.0f);
    glVertex2f(73.0f, 38.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(77.0f, 40.5f);
    glVertex2f(80.0f, 40.5f);
    glVertex2f(80.0f, 38.0f);
    glVertex2f(77.0f, 38.0f);
    glEnd();

    glColor3f(0.52f, 0.37f, 0.36f);
    glBegin(GL_TRIANGLES);
    glVertex2f(73.0f, 42.0f);
    glVertex2f(78.0f, 46.0f);
    glVertex2f(84.0f, 42.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(78.5f, 40.5f);
    glVertex2f(78.5f, 38.0f);
    glEnd();

    /* --------
        ROAD
    -----------*/
    glColor3f(0.91f, 0.76f, 0.50f);
    glBegin(GL_QUADS);
    glVertex2f(76.0f, 38.0f);
    glVertex2f(81.0f, 38.0f);
    glVertex2f(79.0f, 33.0f);
    glVertex2f(75.0f, 33.0f);

    glVertex2f(75.0f, 33.0f);
    glVertex2f(79.0f, 33.0f);
    glVertex2f(78.0f, 28.0f);
    glVertex2f(74.0f, 28.0f);

    glVertex2f(74.0f, 28.0f);
    glVertex2f(78.0f, 28.0f);
    glVertex2f(75.0f, 24.0f);
    glVertex2f(71.0f, 24.0f);

    glVertex2f(71.0f, 24.0f);
    glVertex2f(75.0f, 24.0f);
    glVertex2f(74.0f, 20.0f);
    glVertex2f(70.0f, 20.0f);

    glVertex2f(70.0f, 20.0f);
    glVertex2f(74.0f, 20.0f);
    glVertex2f(75.0f, 16.0f);
    glVertex2f(71.0f, 16.0f);

    glVertex2f(71.0f, 16.0f);
    glVertex2f(75.0f, 16.0f);
    glVertex2f(74.0f, 12.0f);
    glVertex2f(70.0f, 12.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(74.0f, 12.0f);
    glVertex2f(72.0f, 8.0f);
    glVertex2f(71.0f, 4.0f);
    glVertex2f(69.0f, 0.0f);
    glVertex2f(65.0f, 0.0f);
    glVertex2f(67.0f, 4.0f);
    glVertex2f(68.0f, 8.0f);
    glVertex2f(70.0f, 12.0f);
    glEnd();

    /* ----------
        TURBINE
    -------------*/

    glColor3f(0.90f, 0.91f, 0.98f);
    glBegin(GL_QUADS);
    glVertex2f(86.0f, 60.0f);
    glVertex2f(88.0f, 60.0f);
    glVertex2f(88.0f, 50.0f);
    glVertex2f(86.0f, 50.0f);
    glEnd();


    glColor3f(0.658824f, 0.658824f, 0.658824f);
    drawCircle(1, 87, 60);

    glColor3f(0.560784f, 0.560784f, 0.737255f);

    glBegin(GL_QUADS);
    glVertex2f(82.0f, 64.0f);
    glVertex2f(85.0f, 63.0f);
    glVertex2f(87.0f, 60.0f);
    glVertex2f(84.0f, 61.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(88.0f, 63.0f);
    glVertex2f(91.0f, 65.0f);
    glVertex2f(90.0f, 62.0f);
    glVertex2f(87.0f, 60.0f);

    glVertex2f(86.0f, 57.0f);
    glVertex2f(87.0f, 60.0f);
    glVertex2f(88.0f, 57.0f);
    glVertex2f(87.0f, 54.0f);
    glEnd();

    /* -------------
       A BIG HOUSE
    ----------------*/
    glColor3ub(175, 146, 141);
    glBegin(GL_QUADS);

    glVertex2f(90, 20);
    glVertex2f(95.788, 28);
    glVertex2f(97, 27);
    glVertex2f(92, 20);

    glVertex2f(96, 28);
    glVertex2f(108, 28);
    glVertex2f(114, 20);
    glVertex2f(100, 20);

    glColor3ub(222, 186, 111);

    glVertex2f(92, 20);
    glVertex2f(100, 20);
    glVertex2f(100, 10);
    glVertex2f(92, 10);

    glVertex2f(100, 20);
    glVertex2f(113, 20);
    glVertex2f(113, 10);
    glVertex2f(100, 10);

    glColor3ub(133, 89, 82);

    glVertex2f(88, 8);
    glVertex2f(90, 10);
    glVertex2f(115, 10);
    glVertex2f(117, 8);

    glColor3ub(148, 171, 151);

    glVertex2f(94, 17);
    glVertex2f(97, 17);
    glVertex2f(97, 14);
    glVertex2f(94, 14);

    glVertex2f(105, 15);
    glVertex2f(108, 15);
    glVertex2f(108, 10);
    glVertex2f(105, 10);

    glEnd();


    glColor3ub(222, 186, 111);
    glBegin(GL_TRIANGLES);
    glVertex2f(92, 20);
    glVertex2f(97, 27);
    glVertex2f(100, 20);
    glEnd();

    /* -------------
       SMALL BIRDS
    ----------------*/
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.7);
    glBegin(GL_LINES);
    glVertex2f(101.0f+x_bird, 54.0f+y_bird);
    glVertex2f(102.0f+x_bird, 53.0f+y_bird);

    glVertex2f(102.0f+x_bird, 53.0f+y_bird);
    glVertex2f(103.0f+x_bird, 54.0f+y_bird);

    glVertex2f(104.0f+x_bird, 54.0f+y_bird);
    glVertex2f(105.0f+x_bird, 53.0f+y_bird);

    glVertex2f(105.0f+x_bird, 53.0f+y_bird);
    glVertex2f(106.0f+x_bird, 54.0f+y_bird);

    glVertex2f(107.0f+x_bird, 54.0f+y_bird);
    glVertex2f(108.0f+x_bird, 53.0f+y_bird);

    glVertex2f(108.0f+x_bird, 53.0f+y_bird);
    glVertex2f(109.0f+x_bird, 54.0f+y_bird);

    glVertex2f(102.0f+x_bird, 57.0f+y_bird);
    glVertex2f(103.0f+x_bird, 56.0f+y_bird);

    glVertex2f(103.0f+x_bird, 56.0f+y_bird);
    glVertex2f(104.0f+x_bird, 57.0f+y_bird);

    glVertex2f(105.0f+x_bird, 57.0f+y_bird);
    glVertex2f(106.0f+x_bird, 56.0f+y_bird);

    glVertex2f(106.0f+x_bird, 56.0f+y_bird);
    glVertex2f(107.0f+x_bird, 57.0f+y_bird);

    glVertex2f(104.0f+x_bird, 60.0f+y_bird);
    glVertex2f(105.0f+x_bird, 59.0f+y_bird);

    glVertex2f(105.0f+x_bird, 59.0f+y_bird);
    glVertex2f(106.0f+x_bird, 60.0f+y_bird);

    glEnd();

    /* ----------
       3RD TREE
    -------------*/
    glColor3f(0.81f, 0.71f, 0.23f);
    glBegin(GL_QUADS);
    glVertex2f(103.0f, 51.0f);
    glVertex2f(106.0f, 51.0f);
    glVertex2f(106.0f, 35.0f);
    glVertex2f(103.0f, 35.0f);
    glEnd();

    glColor3f(0.137255f, 0.556863f, 0.137255f);
    drawCircle(4, 103, 53);
    drawCircle(4, 106, 53);
    drawCircle(3, 103, 56);
    drawCircle(3, 106, 56);
    drawCircle(2, 103, 58);
    drawCircle(2, 104.5, 58);
    drawCircle(2, 106, 58);
    drawCircle(2, 104.5, 59);


    /* start processing buffered OpenGL routines */
    glutSwapBuffers();
}
void init (void)
{
    /* select clearing (background) color */
    glClearColor (0.91, 0.76, 0.65, 0.0);

    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 140.0, 0.0, 120.0, -50.0, 50.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (900, 700);
    glutInitWindowPosition (100, 50);
    glutCreateWindow ("A Village Scenario");
    init ();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}


void timer(int) {

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);

    int objCount = 0;

    (y_sun < 15) ? (y_sun += 0.05) : (objCount++);
    (y_ballon < 30) ? (y_ballon += 0.15) : (objCount++);

    if(objCount == 2) {

        if(x_bird < 22) {
            x_bird += 0.055;
            y_bird += 0.075;
        }


        switch(cloud_state) {
            case 1:
                if(x_left_cloud <= 30) {
                    x_left_cloud += 0.05;
                    x_right_cloud -= 0.05;
                }
                else
                    cloud_state = -1;
                break;
            case -1:
                if(x_left_cloud >= 2) {
                    x_left_cloud -= 0.05;
                    x_right_cloud += 0.05;
                }
                else
                    cloud_state = 1;
                break;
        }

    }
}

