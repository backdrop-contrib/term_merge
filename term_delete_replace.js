(function ($) {
$(document).ready(function() {

  function setFormState() {
    if (!$('#edit-replacement-term-replace').is(':checked')) {
      setElementEnabledState($('#edit-replacement-term'), false);
      setElementEnabledState($('#edit-replacement-term-new'), false);
    } else if ($('#edit-replacement-term').val() != 'create_replace_new_8563') {
      setElementEnabledState($('#edit-replacement-term'), true);
      setElementEnabledState($('#edit-replacement-term-new'), false);
    } else {
      setElementEnabledState($('#edit-replacement-term'), true);
      setElementEnabledState($('#edit-replacement-term-new'), true); 
    }
  }
  
  function setElementEnabledState($element, enabled) {
    if (enabled) {
      $element.removeAttr('disabled');
      $element.parents('div.form-item').removeClass('disabled');
    } else {
      $element.attr('disabled', true);
      $element.parents('div.form-item').addClass('disabled');
    }
  }
  
  setFormState();
  $('#edit-replacement-term-replace').bind('click.replacement-term-replace', setFormState);
  $('#edit-replacement-term').bind('change.replacement-term', setFormState);
	
	var $firstOption = $('#edit-replacement-term option:first');
	$firstOption.addClass('new-term');
	$firstOption.text($firstOption.text().replace('<--- ', '').replace(' --->', ''));
	
});
})(jQuery);