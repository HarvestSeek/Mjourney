#include <cstdio>

int main() {
    FILE *src = fopen("config.txt", "r");
    FILE *dst = fopen("result.txt", "w");
    const int M = 30;
    int row, col;
    char t[M];
    fscanf(src, "%d %d\n", &row, &col);
    fprintf(dst, "<table class=\"simp\" style=\"margin-left:0px;\" align=left>\n<tr>\n    <td class=\"corner\">&emsp;</td>\n");

    for (int j = 1; j < col; ++j) {
        fscanf(src, "%s ", t);
        fprintf(dst, "    <td class=\"firstrow\">%s</td>\n", t);
    }
    fscanf(src, "E\n");
    fprintf(dst, "</tr>\n");
    
    for (int i = 1; i < row; ++i) {
        fprintf(dst, "<tr>\n");
        for (int j = 0; j < col; ++j) {
            fscanf(src, "%s ", t);
            if (j == 0)
                fprintf(dst, "    <td class=\"firstcol\">%s</td>\n", t);
            else 
                fprintf(dst, "    <td class=\"general\">%s</td>\n", t);
        }
        fscanf(src, "E\n");
        fprintf(dst, "</tr>\n");
    }  
    fprintf(dst, "</table>");

    fclose(src);
    fclose(dst);
}