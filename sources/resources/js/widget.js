function funcOn() {

    $('.button-wrap').on("click", function(){
          $(this).addClass('button-active');
    });

}

function funcOff() {

        $('.button-wrap').on("click", function(){
          $(this).removeClass('button-active');
        });
}

function func(stateStr) {
    //alert(stateStr);
    if (stateStr === "ON")
    {
        $('.button-wrap').on("click", function(){
              $(this).addClass('button-active');
        });
    }
    else if (stateStr === "OFF")
    {
        $('.button-wrap').on("click", function(){
          $(this).removeClass('button-active');
        });
    }


}
