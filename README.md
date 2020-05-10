# Fractol

Fractol is a program developed for my learning course at 21 school for the exploration of Fractals.

![](fractol.gif)
Several options are available (see [Keyboard shortcuts](https://github.com/TheWeaklessOne/fractol#keyboard-shortcuts) or/and [Mouse controls](https://github.com/TheWeaklessOne/fractol#mouse-controls) sections for more infos) :
* Zoom and unzoom
* Change the number of iterations
* Move the current fractal
* Edit the display gradient
* Navigate between fractals
* Edit the shape of the fractal with the position of the mouse (not for all fractals)

## Install & launch
```bash
git clone https://github.com/TheWeaklessOne/fractol ~/Fractol
cd ~/Fractol && && make && ./fractol julia
```
You have to launch the program with a parameter. This is the name of the fractal you would like to open at the execution of the program. This parameter as to be the name of a valid fractal (Julia, Mandelbrot or Tricorn).<br />

Example :

Open the fractol menu ⇣
```bash
./fractol menu
```
![fractol screeneshot](https://i.imgur.com/Tvia8MZ.png)
## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program (aka quit/exit)</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change the display gradient (aka change color)</td>
<td valign="top" align="center"><kbd>&nbsp;shift&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the up (aka move up)</td>
<td valign="top" align="center"><kbd>&nbsp;▲&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the down (aka move down)</td>
<td valign="top" align="center"><kbd>&nbsp;▼&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the left (aka width move left)</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the right (aka move right)</td>
<td valign="top" align="center"><kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Show/close hint</td>
<td valign="top" align="center"><kbd>&nbsp;Z/X&nbsp;</kbd></td>
</tr>
<td valign="top" height="30px">Return to menu</td>
<td valign="top" align="center"><kbd>&nbsp;RMB&nbsp;</kdb></td>
</tr>
</tbody>
</table>

## Mouse controls

<table width="100%">
<thead>
<tr>
<td width="60%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Control(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Increase the number of iterations and the global size of the fractal (aka zoom) </td>
<td valign="top" align="center"><kbd>&nbsp;scroll up&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the number of iterations and the global size of the fractal (aka unzoom)</td>
<td valign="top" align="center"><kbd>&nbsp;scroll down&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Enable or disable the mouse controls</td>
<td valign="top" align="center"><kbd>&nbsp;LMB&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Return to menu</td>
<td valign="top" align="center"><kbd>&nbsp;RMB&nbsp;</kdb></td>
</tr>
</tbody>
</table>
