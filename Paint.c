#include<GL/gl.h>
#include<GL/glext.h>
#include<H:/OpenGL/glut.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


//Function and menu defintions
void resetCoordinates(void);
void drawLine(int x, int y);
void drawRectangle(int x, int y);
void drawTriangle(int x, int y);
void drawPoint(int x, int y);
void mouse(int button, int state, int x, int y);
void init(void);
void display(void);
void clearScreen(void);
void action_menu(int id);
void whites_menu(int id);
void grays_menu(int id);
void blues_menu(int id);
void greens_menu(int id);
void yellows_menu(int id);
void browns_menu(int id);
void oranges_menu(int id);
void pinks_menu(int id);
void defineMenus(void);

struct Point {
    float x;
    float y;
};

//Global variables
GLsizei windowHeight = 500, windowWidth = 500;

//Colour rgb variables
float red = 0.0, green = 0.0, blue = 0.0;

//Deterines shape to draw - Default is line at startup
int selected_shape = 1;

//variable for which color category shade to select
int selected_color_category = 0;

// Drawing function variables
struct Point drawCoordinates[3];
int draw_count = 0;

//variable for transparency - default is no transparency
float transparency = 1.0;

//function to reset the draw coordinates after drawing a shape
void resetCoordinates(void) {
    int i;
    for (i = 0; i < 3; ++i) {
        drawCoordinates[i].x = 0.0;
        drawCoordinates[i].y = 0.0;
    }
}

//Function to draw a line
void drawLine(int x, int y) {
    drawCoordinates[draw_count].x = x;
    drawCoordinates[draw_count].y = windowHeight - y;
    draw_count++;

	//takes the rgb and transparency parameters
    glColor4f(red, green, blue,transparency);
    if (draw_count == 2) {
        glBegin(GL_LINES);
        glVertex2f(drawCoordinates[0].x, drawCoordinates[0].y);
        glVertex2f(drawCoordinates[1].x, drawCoordinates[1].y);
        glEnd();
        draw_count = 0;
    }
    glutPostRedisplay();
}

//Function to draw rectangle
void drawRectangle(int x, int y) {
    glColor4f(red, green, blue, transparency );

    drawCoordinates[draw_count].x = x;
    drawCoordinates[draw_count].y = windowHeight - y;
    draw_count++;
    if (draw_count == 2) {
        glRectf(drawCoordinates[0].x, drawCoordinates[0].y,
                drawCoordinates[1].x, drawCoordinates[1].y);
        draw_count = 0;
    }
    glutPostRedisplay();
}

//Function to draw rectangle
void drawTriangle(int x, int y) {
    glColor4f(red,green,blue,transparency);
    drawCoordinates[draw_count].x = x;
    drawCoordinates[draw_count].y = windowHeight - y;
    draw_count++;

    if (draw_count == 3) {
		glColor4f(red,green,blue,transparency);
        glBegin(GL_TRIANGLES);
        glVertex2f(drawCoordinates[0].x, drawCoordinates[0].y);
        glVertex2f(drawCoordinates[1].x, drawCoordinates[1].y);
        glVertex2f(drawCoordinates[2].x, drawCoordinates[2].y);
        glEnd();
        draw_count = 0;
    }
    glutPostRedisplay();
}

//Function to draw a point
void drawPoint(int x, int y) {
    glColor4f(red, green, blue, transparency);
    x = x;
    y = windowHeight - y;
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(x ,y);
    glEnd();
    glutPostRedisplay();
}

//Manages which shape to draw depending on mouse click
void mouse(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        switch(selected_shape) {
        case 1  :
            drawLine(x,y);
            break;
        case 2  :
            drawRectangle(x,y);
            break;
        case 3  :
            drawTriangle(x,y);
            break;
        case 4  :
            drawPoint(x,y);
            break;
        }
        glFlush();
    }
}

void display(void) {
	//Allows color transparency
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable( GL_BLEND );
}



//Sets the state
void init(void) {
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, windowWidth, windowHeight);
	//glEnable (GL_BLEND);
	//glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, windowWidth, 0.0, windowHeight,  -1.0, 1.0);
    clearScreen();
}

//sets the screen to white
void clearScreen(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}


//User actions on menu screen
void action_menu(int id) {
    if (id == 1) {
        clearScreen();
    } else {
        exit(1);
    }
}

//the below methods are used to change the color variables
//colors are divided by 255 to convert to opengl float type
void whites_menu(int id) {
	if(id == 1) {
		red = 1.0;
		green = 1.0;
		blue = 1.0;
	}
	else if(id == 2) {
		red = 240.0/255;
		green = 244.0/255;
		blue = 230.0/255;
	}
	else if(id == 3) {
		red = 250.0/255;
		green = 235.0/255;
		blue = 215.0/255;
	}
	else if(id == 4) {
		red = 238.0/255;
		green = 213.0/255;
		blue = 183.0/255;
	}
	else if(id == 5) {
		red = 238.0/255;
		green = 203.0/255 ;
		blue = 173.0/255;
	}
}

void grays_menu(int id) {
	if(id == 1) {
		red = 0.0;
		green = 0.0;
		blue = 0.0;

	}
	if(id == 2) {
		red = 105.0/255;
		green = 105.0/255;
		blue = 105.0/255;

	}
	if(id == 3) {
		red = 190.0/255;
		green = 190.0/255;
		blue = 190.0/255;

	}
}

void blues_menu(int id) {
	if(id == 1) {
		red = 0.0;
		green = 0.0;
		blue = 128.0/255;

	}
	if(id == 2) {
		red = 0.0;
		green = 0.0;
		blue = 255/255;

	}
	if(id == 3) {
		red = 0.0;
		green = 255/255;
		blue = 255/255;

	}
}

void greens_menu(int id) {
	if(id == 1) {
		red = 152.0/255;
		green = 251.0/255;
		blue = 152.0/255;

	}
	if(id == 2) {
		red = 50.0/255;
		green = 205.0/255;
		blue = 50/255;

	}
	if(id == 3) {
		red = 34.0/255;
		green = 139.0/255;
		blue = 34.0/255;

	}
}

void yellows_menu(int id) {
	if(id == 1) {
		red = 255.0/255;
		green = 255.0/255;
		blue = 0.0/255;
	}

	if(id == 2) {
		red = 255.0/255;
		green = 255.0/255;
		blue = 224.0/255;
	}

	if(id == 3) {
		red = 255.0/255;
		green = 215.0/255;
		blue = 0.0/255;
	}
}

void browns_menu(int id) {
	if(id == 1) {
		red = 139.0/255;
		green = 69.0/255;
		blue = 19.0/255;
	}

	if(id == 2) {
		red = 160.0/255;
		green = 82.0/255;
		blue = 45.0/255;
	}

	if(id == 3) {
		red = 210.0/255;
		green = 105.0/255;
		blue = 30.0/255;
	}
}

void oranges_menu(int id) {
	if(id == 1) {
		red = 255.0/255;
		green = 0.0/255;
		blue = 0.0/255;
	}

	if(id == 2) {
		red = 255/255;
		green = 99.0/255;
		blue = 71/255;
	}

	if(id == 3) {
		red = 255.0/255;
		green = 165.0/255;
		blue = 0.0/255;
	}

	if(id == 4) {
		red = 250.0/255;
		green = 128.0/255;
		blue = 114.0/255;
	}
}

void pinks_menu(int id) {
	if(id == 1) {
		red = 255.0/255;
		green = 105.0/255;
		blue = 180.0/255;
	}

	if(id == 2) {
		red = 255.0/255;
		green = 182.0/255;
		blue = 193.0/255;
	}

	if(id == 3) {
		red = 238.0/255;
		green = 130.0/255;
		blue = 238.0/255;
	}

	if(id == 4) {
		red = 169.0/255;
		green = 32.0/255;
		blue = 240.0/255;
	}
}

void brightness_menu(int id){
	//increase brightness
	if(id == 1) {
		red = red + .2;
		green = green + .2;
		blue = blue + .2;
	}
	//decrease brightness
	if(id == 2) {
		red = red - .2;
		green = green - .2;
		blue = blue - .2;
	}
}

//changes shape variable
void shape_menu(int id) {
    selected_shape = id;
}

//changes color category variable
void color_category_menu(int id) {
	selected_color_category = id;
}

//changes transparency variable
void transparency_menu(int id){
	if(id == 1) {
		transparency = transparency - 0.1;
	}
	else if(id == 2) {
		transparency = transparency + 0.1;
	}
}

//defines several menus which allow the user to use all the functionalities in the spec
void defineMenus(void) {

    int color_menu_handle, shape_menu_handle, whites_handle, grays_handle, blues_handle, greens_handle, yellows_handle, browns_handle, oranges_handle, pinks_handle, brightness_handle, transparency_handle;

    shape_menu_handle = glutCreateMenu(shape_menu);
    glutAddMenuEntry("Line",     1);
    glutAddMenuEntry("Rectangle", 2);
    glutAddMenuEntry("Triangle", 3);
    glutAddMenuEntry("Point",    4);

	whites_handle = glutCreateMenu(whites_menu);
	glutAddMenuEntry("White", 1);
	glutAddMenuEntry("Linen", 2);
	glutAddMenuEntry("Antique White", 3);
	glutAddMenuEntry("Bisque 2", 4);
	glutAddMenuEntry("Peach Puff 2", 5);

	grays_handle = glutCreateMenu(grays_menu);
	glutAddMenuEntry("black", 1);
	glutAddMenuEntry("Dim Gray", 2);
	glutAddMenuEntry("Gray", 3);

	blues_handle = glutCreateMenu(blues_menu);
	glutAddMenuEntry("Navy", 1);
	glutAddMenuEntry("Medium Blue", 2);
	glutAddMenuEntry("Cyan", 3);

	greens_handle = glutCreateMenu(greens_menu);
	glutAddMenuEntry("Pale Green", 1);
	glutAddMenuEntry("Lime Green", 2);
	glutAddMenuEntry("Forest Green", 3);

	yellows_handle = glutCreateMenu(yellows_menu);
	glutAddMenuEntry("Yellow", 1);
	glutAddMenuEntry("Light Yellow", 2);
	glutAddMenuEntry("Gold", 3);

	browns_handle = glutCreateMenu(browns_menu);
	glutAddMenuEntry("Saddle Brown", 1);
	glutAddMenuEntry("Sienna", 2);
	glutAddMenuEntry("Chocolate", 3);

	oranges_handle = glutCreateMenu(oranges_menu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Tomato", 2);
	glutAddMenuEntry("Orange", 3);
	glutAddMenuEntry("Salmon", 4);

	pinks_handle = glutCreateMenu(pinks_menu);
	glutAddMenuEntry("Hot Pink", 1);
	glutAddMenuEntry("Light Pink", 2);
	glutAddMenuEntry("Violet", 3);
	glutAddMenuEntry("Purple", 4);

    color_menu_handle = glutCreateMenu(color_category_menu);
    glutAddSubMenu("Whites/Pastels", whites_handle);
    glutAddSubMenu("Grays/Black", grays_handle);
    glutAddSubMenu("Blues", blues_handle);
	glutAddSubMenu("Greens",greens_handle);
    glutAddSubMenu("Yellows",yellows_handle);
    glutAddSubMenu("Browns",browns_handle);
    glutAddSubMenu("Oranges/Reds",oranges_handle);
    glutAddSubMenu("Pinks/Purples",pinks_handle);

	transparency_handle = glutCreateMenu(transparency_menu);
	glutAddMenuEntry("Increase Transparency", 1);
	glutAddMenuEntry("Decrease Transparency", 2);

	brightness_handle = glutCreateMenu(brightness_menu);
	glutAddMenuEntry("Increase Brightness", 1);
	glutAddMenuEntry("Decrease Brightness", 2);

	glutCreateMenu(action_menu);
    glutAddSubMenu("Shape", shape_menu_handle);
    glutAddSubMenu("Color shade", color_menu_handle);
    glutAddSubMenu("Color brightness", brightness_handle);
	glutAddSubMenu("Color Transparency", transparency_handle);
    glutAddMenuEntry("Clear", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}


int main(int argc, char **argv) {
    //Initialises glut library
    glutInit(&argc, argv);

    //creates window
    glutInitWindowSize(windowHeight,windowWidth);
    glutCreateWindow("My Window");

    //redraws display
    glutDisplayFunc(display);

    //Caleed when there's mouse clicks
    glutMouseFunc(mouse);

    init();

    //Menu code
    defineMenus();

    //main loop
    glutMainLoop();
}
