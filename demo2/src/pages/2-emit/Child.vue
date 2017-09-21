<template>
  <div class="yellow-box">
   <h2> 子组件(黄色背景)</h2>
    <input type="text" v-model="message">
    <button @click="send"> 发送 </button>
  </div>
</template>
<script>
  export default {
    data(){
        return {
            message:""
        }
    },
    methods:{
      send(){
        this.$emit('emitMessage', this.message);
      }
    }
  }
</script>
<style>
  .grey-box{
    background-color: gainsboro;
    height: 400px;
  }
  .grey-box input{
    width: 300px;
    height: 35px;
    line-height: 35px;
    font-size: 18px;
  }
  .yellow-box{
    width: 500px;
    margin-left: 80px;
    margin-top: 30px;
    background-color: yellow;
    height: 100px;
  }
</style>