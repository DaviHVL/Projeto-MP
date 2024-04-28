#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE( "Numeros romanos - algarismos inv�lidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );

    REQUIRE( romanos_para_decimal("i") == -1 );

    REQUIRE( romanos_para_decimal("OP") == -1 );

    REQUIRE( romanos_para_decimal("#") == -1 );

    REQUIRE( romanos_para_decimal("8") == -1 );
}

TEST_CASE( "Numeros romanos - algarismos com vdl", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("VV") == -1 );

    REQUIRE( romanos_para_decimal("LL") == -1 );

    REQUIRE( romanos_para_decimal("DD") == -1 );
}

TEST_CASE( "Numeros romanos - algarismos com mais de vezes", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("XIIII") == -1 );

    REQUIRE( romanos_para_decimal("XXXXX") == -1 );

    REQUIRE( romanos_para_decimal("MMMM") == -1 );

    REQUIRE( romanos_para_decimal("XIXIII") == -1 );

    REQUIRE( romanos_para_decimal("LLLL") == -1 );
}

TEST_CASE( "Numeros romanos - algarismos com resultados", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("XII") == 12 );

    REQUIRE( romanos_para_decimal("V") == 5 );

    REQUIRE( romanos_para_decimal("CC") == 200 );

    REQUIRE( romanos_para_decimal("XIV") == 14 );

    REQUIRE( romanos_para_decimal("MD") == 1500 );
}

TEST_CASE( "Numeros romanos - casos certos e errados", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("III") == 3 );

    REQUIRE( romanos_para_decimal("IX") == 9 );

    REQUIRE( romanos_para_decimal("XIV") == 14 );

    REQUIRE( romanos_para_decimal("LXVII") == 67 );

    REQUIRE( romanos_para_decimal("XCIX") == 99 );

    REQUIRE( romanos_para_decimal("IIII") == -1 );

    REQUIRE( romanos_para_decimal("VX") == -1 );

    REQUIRE( romanos_para_decimal("XIX") == 19 );

    REQUIRE( romanos_para_decimal("LL") == -1 );

    REQUIRE( romanos_para_decimal("DM") == -1 );
}
