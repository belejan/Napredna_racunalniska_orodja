(* ::Package:: *)

(* ::Input:: *)
(*MonteCarlo[StTock_] :=*)
(*    Module[{Tocke = RandomReal[{-1, 1}, {StTock, 2}], Krog = {}, Kvadrat={}},*)
(*        For[i = 1, i <= StTock, i++,*)
(*            If[Norm[Tocke[[i]]] <= 1,*)
(*                AppendTo[Krog, Tocke[[i]]]];*)
(*            If[Norm[Tocke[[i]]] >= 1,*)
(*                AppendTo[Kvadrat, Tocke[[i]]]]];*)
(*        {Krog, Kvadrat}]*)
