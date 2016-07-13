# SVG-Project

Работа със SVG файлове
В рамките на този проект трябва да се разработи приложение, което работи с SVG файлове.
Приложението трябва да може да зарежда фигури от файла, да извършва върху тях дадени
операции, след което да може да записва промените обратно на диска.
За улеснение, в рамките на проекта ще работим само с основните фигури (basic shapes) в SVG.
Приложението ви трябва да поддържа поне три от тях. Например можете да изберете да се
поддържат линия, кръг и правоъгълник. За повече информация за това кои са базовите фигури,
вижте https://www.w3.org/TR/SVG/shapes.html.
Също така, за улеснение считаме, че координатната система, в която работим е тази по
подразбиране: положителната ос X сочи надясно, а положителната ос Y сочи надолу.
Дизайнът на приложението трябва да е такъв, че да позволява при нужда лесно да можете да
добавите поддръжка на нови фигури.
Когато зареждате съдържанието на един SVG файл, трябва да прочетете само фигурите, които
приложението ви поддържа и можете да игнорирате всички останали SVG елементи.
След като заредите фигурите, потребителят трябва да може да изпълнява дадените в
следващия раздел команди, които добавят, изтриват или променят фигурите.
Когато записвате фигурите във файл, трябва да генерирате валиден SVG файл
Операции
# Print Извежда на екрана всички фигури.
# Create Създава нова фигура.
# Erase Изтрива фигура
# Translate Транслира една или всички фигури. Ако потребителят не посочи конкретна
# фигура се транслират всички фигури; ако се посочи конкретна – променя се
# само тя.
# Within Извежда на екрана всички фигури, които попадат в даден регион.
# Потребителят може да укаже какъв да бъде регионът – кръг или
# правоъгълник

>Open
Зарежда съдържанието на даден файл. Ако такъв не съществува се създава нов с празно
съдържание.
Останалите команди могат да се изпълняват само ако има успешно зареден файл.
> open C:\Temp\file.xml
Successfully opened file.xml
Close
Затваря текущо отворения файл.
СУ „Св. Климент Охридски“
Факултет по математика и информатика
Курсов проект по ООП (Информатика)
Летен семестър 2015/2016
Последна редакция: 13 май 2016 г. стр. 3 от 8
> close
Successfully closed file.xml
Save
Записва направените промени обратно в същия файл, от който са били прочетени данните.
> save
Successfully saved file.xml
Save As
Записва направените промени във файл, като позволява на потребителя да укаже неговия път.
> saveas "C:\Temp\another file.xml"
Successfully saved another file.xml
Exit
Излиза от програмата
> exit


Примерен SVG файл figures.svg
<?xml version="1.0" standalone="no"?>
<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN"
 "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">
<svg>
 <rect x="5" y="5" width="10" height="10" fill="green" />
 <circle cx="5" cy="5" r="10" fill="blue" />
 <rect x="100" y="60" width="10" height="10" fill="red" />
</svg>

 Пример за работа на програмата
> open figures.svg
Successsfully opened figures.svg
> print
1. rectangle 5 5 10 10 green
2. circle 5 5 10 blue
3. rectangle 100 60 10 10 red
> create rectangle -1000 -1000 10 20 yellow
Successfully created rectangle (4)
> print
1. rectangle 1 1 10 20 green
2. circle 5 5 10 blue
3. rectangle 100 60 10 10 red
4. rectangle 1000 1000 10 20 yellow
> within rectangle 0 0 30 30
1. rectangle 5 5 10 10 green
2. circle 5 5 10 blue
> within circle 0 0 5
No figures are located within circle 0 0 5
> erase 2
Erased a circle (2)
> erase 100
There is no figure number 100!
> print
1. rectangle 5 5 10 10 green
2. rectangle 100 60 10 10 red
3. rectangle 1000 1000 10 20 yellow
> translate vertical=10 horizontal=100
Translated all figures
> print
1. rectangle 105 15 10 10 green
2. rectangle 200 70 10 10 red
3. rectangle 1100 1010 10 20 yellow
> save
Successfully saved the changes to figures.svg
> exit
Exit
