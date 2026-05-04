#include "glos.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <corecrt_math.h>

GLfloat rotX = 20.0f;
GLfloat rotY = 0.0f;

GLfloat unghiRoti = 0.0f;

void CALLBACK rotireMouse(AUX_EVENTREC* event) {
    rotY += 0.75f; 
    unghiRoti += 5.0f; 
    if (unghiRoti > 360) 
        unghiRoti -= 360;
}

void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -15.0f);

    glRotatef(rotX, 1.0, 0.0, 0.0);
    glRotatef(rotY, 0.0, 1.0, 0.0);

    // CILINDRU PRINCIPAL (CAZAN)
    glPushMatrix();
    glColor3f(0.30f, 0.30f, 0.30f);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        float r = 1.2f;
        float lungime = 7.5f;
        glVertex3f(0.0f, r * sinf(rad), r * cosf(rad));
        glVertex3f(lungime, r * sinf(rad), r * cosf(rad));
    }
    glEnd();
    glPopMatrix();

    // CABINA MECANIC
    glPushMatrix();
    glColor3f(0.30f, 0.30f, 0.30f);
    float r = 1.1f;
    float w_factor = 1.9f;
    float h_factor = 3.9f;
    glTranslatef(-0.01f, 0.5f, 0.0f);

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 450; i += 90) {
        float rad = (i + 45) * 3.14159f / 180.0f;
        glVertex3f(0.0f, r * sinf(rad) * h_factor, r * cosf(rad) * w_factor);
        glVertex3f(-3.9f, r * sinf(rad) * h_factor, r * cosf(rad) * w_factor);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 90) {
        float rad = (i + 45) * 3.14159f / 180.0f;
        glVertex3f(0.0f, r * sinf(rad) * h_factor, r * cosf(rad) * w_factor);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 90) {
        float rad = (i + 45) * 3.14159f / 180.0f;
        glVertex3f(-3.9f, r * sinf(rad) * h_factor, r * cosf(rad) * w_factor);
    }
    glEnd();
    glPopMatrix();

    // SASIU (PARTEA INFERIOARA)
    glPushMatrix();
    glColor3f(0.25f, 0.25f, 0.25f);
    glTranslatef(0.0f, -1.5f, 0.0f);
    float w_s = 1.6f, h_s = 1.3f;
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 450; i += 90) {
        float rad = (i + 45) * 3.14159f / 180.0f;
        glVertex3f(6.8f, sinf(rad) * h_s, cosf(rad) * w_s);
        glVertex3f(0.0f, sinf(rad) * h_s, cosf(rad) * w_s);
    }
    glEnd();
    glPopMatrix();

    // COS DE FUM
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    glTranslatef(6.5f, 1.1f, 0.0f);
    float r_baza = 0.3f;
    float r_mijloc = 0.8f;
    float r_capat = 0.4f;
    float h_gat = 0.8f;
    float h_total = 1.6f;
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex3f(r_baza * cosf(rad), 0.0f, r_baza * sinf(rad));
        glVertex3f(r_mijloc * cosf(rad), h_gat, r_mijloc * sinf(rad));
    }
    glEnd();
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex3f(r_mijloc * cosf(rad), h_gat, r_mijloc * sinf(rad));
        glVertex3f(r_capat * cosf(rad), h_total, r_capat * sinf(rad));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex3f(r_capat * cosf(rad), h_total, r_capat * sinf(rad));
    }
    glEnd();
    glPopMatrix();

    // DOMURI CAZAN
    glPushMatrix();
    glColor3f(0.25f, 0.25f, 0.25f);
    glTranslatef(3.5f, 1.1f, 0.0f);
    float r_dom = 0.7f;
    float h_dom = 0.8f;
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex3f(r_dom * cosf(rad), 0.0f, r_dom * sinf(rad));
        glVertex3f(r_dom * cosf(rad), h_dom, r_dom * sinf(rad));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex3f(r_dom * cosf(rad), h_dom, r_dom * sinf(rad));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.25f, 0.25f, 0.25f);
    glTranslatef(1.5f, 1.1f, 0.0f);
    float r_dom2 = 0.6f;
    float h_dom2 = 0.6f;
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex3f(r_dom2 * cosf(rad), 0.0f, r_dom2 * sinf(rad));
        glVertex3f(r_dom2 * cosf(rad), h_dom2, r_dom2 * sinf(rad));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex3f(r_dom2 * cosf(rad), h_dom2, r_dom2 * sinf(rad));
    }
    glEnd();
    glPopMatrix();

	// BOT LOCOMOTIVA
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslatef(7.5f, 0.0f, 0.0f);
    float r_cil = 1.2f;
    float proeminenta = 0.7f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(proeminenta, 0.0f, 0.0f);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex3f(0.0f, r_cil * sinf(rad), r_cil * cosf(rad));
    }
    glEnd();
    glPopMatrix();

    // ACOPERIS CABINA
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslatef(0.0f, 3.2f, 0.0f);
    float latime_acop = 2.2f;
    float lungime_acop = 4.5f;
    float inaltime_boltă = 0.5f;
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 180; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex3f(0.5f, sinf(rad) * inaltime_boltă, cosf(rad) * latime_acop);
        glVertex3f(-lungime_acop, sinf(rad) * inaltime_boltă, cosf(rad) * latime_acop);
    }
    glEnd();
    glPopMatrix();

    // PLUG
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslatef(6.81f, -1.2f, 0.0f);
    float latime_p = 1.6f;
    float inaltime_p = 1.0f;
    float lungime_e = 0.85f;
    glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, latime_p);
        glVertex3f(lungime_e, -inaltime_p, 0.0f);
        glVertex3f(0.0f, -inaltime_p, latime_p);
        glVertex3f(0.0f, 0.0f, -latime_p);
        glVertex3f(lungime_e, -inaltime_p, 0.0f);
        glVertex3f(0.0f, -inaltime_p, -latime_p);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(0.0f, 0.0f, latime_p);
        glVertex3f(lungime_e, -inaltime_p, 0.0f);
        glVertex3f(lungime_e, -inaltime_p, 0.0f);
        glVertex3f(0.0f, 0.0f, -latime_p);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.0f, -inaltime_p, latime_p);
        glVertex3f(lungime_e, -inaltime_p, 0.0f);
        glVertex3f(0.0f, -inaltime_p, -latime_p);
    glEnd();
    glPopMatrix();

    // ROTI MOCANITA
    float pozitiiX[] = { 1.5f, 3.4f, 5.3f };
    float razaRoata = 0.9f;
    float distantaZ = 1.3f;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            float z_pos = (j == 0) ? distantaZ : -distantaZ;

            glPushMatrix();
            glTranslatef(pozitiiX[i], -1.9f, z_pos);
            glRotatef(unghiRoti, 0.0f, 0.0f, 1.0f);

            glColor3f(0.1f, 0.1f, 0.1f);

            glBegin(GL_QUAD_STRIP);
            for (int k = 0; k <= 360; k += 20) {
                float rad = k * 3.14159f / 180.0f;
                glVertex3f(razaRoata * cosf(rad), razaRoata * sinf(rad), 0.1f);
                glVertex3f(razaRoata * cosf(rad), razaRoata * sinf(rad), -0.1f);
            }
            glEnd();

            // SPITE ROTI
            glBegin(GL_LINES);
            for (int k = 0; k < 360; k += 45) {
                float rad = k * 3.14159f / 180.0f;
                glVertex3f(0.0f, 0.0f, 0.0f);
                glVertex3f(razaRoata * cosf(rad), razaRoata * sinf(rad), 0.0f);
            }
            glEnd();
            glPopMatrix();
        }
    }

    // BIELE TRANSMISIE 
    float distantaManivela = 0.3f; 
    float grosimeBiela = 0.15f;

    float offset_x = distantaManivela * cosf(unghiRoti * 3.14159f / 180.0f);
    float offset_y = distantaManivela * sinf(unghiRoti * 3.14159f / 180.0f);

    for (int j = 0; j < 2; j++) {
        float z_pos = (j == 0) ? (distantaZ + 0.15f) : (-distantaZ - 0.15f); 

        glPushMatrix();
        glColor3f(0.5f, 0.5f, 0.5f); 

        glBegin(GL_QUADS);
            glVertex3f(pozitiiX[0] + offset_x, -1.9f + offset_y + grosimeBiela, z_pos);
            glVertex3f(pozitiiX[2] + offset_x, -1.9f + offset_y + grosimeBiela, z_pos);
            glVertex3f(pozitiiX[2] + offset_x, -1.9f + offset_y - grosimeBiela, z_pos);
            glVertex3f(pozitiiX[0] + offset_x, -1.9f + offset_y - grosimeBiela, z_pos);
        glEnd();

        // BURDUF BIELE
        for (int i = 0; i < 3; i++) {
            glPushMatrix();
            glTranslatef(pozitiiX[i] + offset_x, -1.9f + offset_y, z_pos);
            glColor3f(0.2f, 0.2f, 0.2f);
            glBegin(GL_POLYGON);
                for (int k = 0; k < 360; k += 30) {
                    float rad = k * 3.14159f / 180.0f;
                    glVertex3f(0.2f * cosf(rad), 0.2f * sinf(rad), (j == 0 ? 0.02f : -0.02f));
                }
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(52.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB | AUX_DEPTH);
    auxInitPosition(0, 0, 1000, 680);
    auxInitWindow("Mocanita");
    auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSELOC, rotireMouse);
    myinit();
    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return 0;
}