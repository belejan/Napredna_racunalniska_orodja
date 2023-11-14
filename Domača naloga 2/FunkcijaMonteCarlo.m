(* ::Package:: *)

BeginPackage["FunkcijaMonteCarlo`"]
MonteCarlo::usage = "Vrne nam to\[CHacek]ke v krogu in izven njega"
Begin["`Private`"];

MonteCarlo[StTock_]:=Module[{Tocke =RandomReal[{-1,1},{StTock,2}], Krog={},Kvadrat={}},
For[i=1,i<=StTock,i++,
If[Sqrt[(Tocke[[i,1]])^2+(Tocke[[i,2]])^2]<=1,
Krog=Append[Krog,Tocke[[i]]],
Kvadrat=Append[Kvadrat,Tocke[[i]]]]];
{Krog,Kvadrat}]

End[];
EndPackage[];



