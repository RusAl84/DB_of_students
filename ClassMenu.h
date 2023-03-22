package org.example;

import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;

public class Drawer {
    private static void fill(int width, String sym) {
        for (int i = 0; i < width; i++) {
            System.out.print(sym);
        }
    }

    public static void drawBorder(int tableWidth) {
        System.out.println();
        System.out.print(" ");
        fill(tableWidth - 1, "-");
        System.out.println("-");
    }

    public static void formatColumn(String str, int maxLen, int tableWidth, boolean header) {
        System.out.print("| ");
        System.out.print(str);
        fill((header ? tableWidth : maxLen) - str.length() - 2, " ");
        System.out.print(" |");
    }

    public static void drawBottom(int tableWidth) {
        ArrayList<String> bottom = new ArrayList<>(2);
        bottom.add("| Примечание: Х - художественная литература; У - учебная литература;");
        bottom.add("| С - справочная литература;");

        for (int i = 0; i < 2; i++) {
            System.out.print(bottom.get(i));
            fill(tableWidth - bottom.get(i).length(), " ");
            System.out.print(" |");
            if (i == 0) {
                System.out.println();
            }
        }
        drawBorder(tableWidth);
    }

    public static void drawLine(@NotNull ArrayList<String> columns, @NotNull ArrayList<Integer> params, int tableWidth) {
        for (int i = 0; i < columns.size(); i++) {
            formatColumn(columns.get(i), params.get(i), tableWidth, false);
        }
    }

    public static int getMaxLen(@NotNull ArrayList<String> names) {
        int max = 0;
        for (String str : names) {
            max = Math.max(str.length(), max);
        }
        return max + 4;
    }

    public static void drawTable(ArrayList<ArrayList<String>> lines, @NotNull ArrayList<String> columns, String title, boolean shouldDrawBottom) {
        ArrayList<Integer> params = new ArrayList<>();
        for (int i = 0; i < columns.size(); i++) {
            ArrayList<String> columnValues = new ArrayList<>();
            columnValues.add(columns.get(i));
            for (ArrayList<String> line : lines) {
                columnValues.add(line.get(i));
            }
            params.add(getMaxLen(columnValues));
        }

        int tableWidth = columns.size() + 3;
        for (Integer i : params) {
            tableWidth += i;
        }
        drawBorder(tableWidth);
        if (title.length() != 0) {
            formatColumn(title, title.length(), tableWidth, true);
            drawBorder(tableWidth);
        }

        for (int i = 0; i < lines.size() + 1; i++) {
            if (i == 0) {
                drawLine(columns, params, tableWidth);
                drawBorder(tableWidth);
                continue;
            }

            drawLine(lines.get(i - 1), params, tableWidth);
            drawBorder(tableWidth);
        }

        if (shouldDrawBottom)
            drawBottom(tableWidth);
    }
}
